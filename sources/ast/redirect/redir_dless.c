/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_dless.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggwin-go <ggwin-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 19:46:10 by dwisoky           #+#    #+#             */
/*   Updated: 2019/10/12 19:49:43 by dwisoky          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"
#include "libft.h"
#include "ft_readline.h"
#include <errno.h>

extern int	g_eof;

static void	close_fd(int fd[2])
{
	close(fd[0]);
	close(fd[1]);
}

static void	ft_reset_fd(int fd[2])
{
	dup2(fd[0], 0);
	dup2(fd[1], 1);
	if (!fd[0])
		close(fd[0]);
	if (!fd[1])
		close(fd[1]);
}

static void	save_fd(int fd[2])
{
	int		tmp_fd;

	fd[0] = 0;
	fd[1] = 1;
	fd[0] = dup(0);
	close(0);
	tmp_fd = open(g_tty, O_RDWR);
	if (tmp_fd)
	{
		dup2(tmp_fd, 0);
		close(tmp_fd);
	}
	fd[1] = dup(1);
	close(1);
	tmp_fd = open(g_tty, O_RDWR);
	if (tmp_fd != 1)
	{
		dup2(tmp_fd, 1);
		close(tmp_fd);
	}
}

extern int	g_eof;

void		redir_dless_push(char *str, int fd)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '$')
			dollar(&i, &str);
		else
			++i;
	}
	ft_putendl_fd(str, fd);
	free(str);
}

int			redir_dless(t_io_redirect *redir)
{
	int				pipefd[2];
	char			*str;
	int				save[2];
	extern t_opt	g_opt;

	if (pipe(pipefd) < 0)
		exit(-1);
	save_fd(save);
	while (1)
	{
		str = ft_readline(g_opt.rl_gnl == 0 ?
							get_var_value("PS2") : "", RL_HEREDOC);
		if (!str && !g_eof)
			return (-1);
		if ((!str || ft_strequ(str, redir->file_name)) && !(g_eof = 0))
			break ;
		redir_dless_push(str, pipefd[1]);
	}
	free(str);
	if (redir->io_number == -1)
		redir->io_number = 0;
	ft_reset_fd(save);
	if (dup2(pipefd[0], redir->io_number) < 0)
		return (redirect_error_fd(redir->io_number));
	close_fd(pipefd);
	return (1);
}
