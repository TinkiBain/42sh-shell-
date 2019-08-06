/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_dless.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwisoky <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 19:46:10 by dwisoky           #+#    #+#             */
/*   Updated: 2019/08/06 19:58:10 by dwisoky          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"
#include "libft.h"
#include "ft_readline.h"

static void close_fd(int fd[2])
{
	close(fd[0]);
	close(fd[1]);
}

int			redir_dless(t_io_redirect *redir)
{
	int	pipefd[2];
	char	*str;

	if (pipe(pipefd) < 0)
		exit(-1);
	while (1)
	{
		str = ft_readline("> ", NULL);
		if (ft_strequ(str, redir->file_name))
			break ;
		ft_putstr_fd(str, pipefd[1]);
		ft_putstr_fd("\n", pipefd[1]);
		free(str);
	}
	free(str);
	if (redir->io_number == -1)
		redir->io_number = 0;	
	if (redir->io_number >= 10000)
	{
		close_fd(pipefd);
		return (redirect_error_fd(redir->io_number));		
	}
	dup2(pipefd[0], redir->io_number);
	close_fd(pipefd);
	return (1);
}
