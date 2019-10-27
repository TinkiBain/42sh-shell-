/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_dless.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwisoky <dwisoky@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 19:46:10 by dwisoky           #+#    #+#             */
/*   Updated: 2019/10/27 21:46:59 by ggwin-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"
#include "libft.h"
#include "ft_readline.h"
#include <errno.h>

extern int	g_eof;

static void	close_fd(int fd[2], int tmp)
{
	extern t_opt	g_opt;

	close(fd[0]);
	close(fd[1]);
	if (!g_opt.rl_gnl && g_opt.rl_in != (unsigned int)tmp)
	{
		close(g_opt.rl_in);
		g_opt.rl_in = tmp;
	}
}

static int	save_fd(void)
{
	int				old_fd;
	extern char		*g_tty_name;
	extern t_opt	g_opt;
	extern int		g_open;

	old_fd = g_opt.rl_in;
	if (g_tty_name)
	{
		g_opt.rl_in = g_open;
	}
	return (old_fd);
}

void		redir_dless_push(char *str, int fd, t_pjobs **local)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '$')
			dollar(&i, &str, local);
		else
			++i;
	}
	ft_putendl_fd(str, fd);
	free(str);
}

int			redir_dless(t_io_redirect *redir, t_pjobs **local)
{
	extern t_opt	g_opt;
	int				pipefd[2];
	int				tmp;
	char			*str;

	if (pipe(pipefd) < 0)
		exit(-1);
	if (!g_opt.rl_gnl)
		tmp = save_fd();
	while (1)
	{
		str = ft_readline(g_opt.rl_gnl == 0 ?
							get_var_value("PS2") : "", RL_HEREDOC);
		if (!str && !g_eof)
			return (-1);
		if ((!str || ft_strequ(str, redir->file_name)) && !(g_eof = 0))
			break ;
		redir_dless_push(str, pipefd[1], local);
	}
	free(str);
	redir->io_number = (redir->io_number == -1) ? 0 : redir->io_number;
	if (dup2(pipefd[0], redir->io_number) < 0)
		return (redirect_error_fd(redir->io_number));
	close_fd(pipefd, tmp);
	return (1);
}
