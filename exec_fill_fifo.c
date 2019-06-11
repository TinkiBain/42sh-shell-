/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_fill_fifo.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwisoky <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/04 19:38:59 by dwisoky           #+#    #+#             */
/*   Updated: 2019/06/11 10:35:32 by dwisoky          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

int			exec_fill_fifo_one_left(char *file)
{
	int		pipefd[2];
	int		fd;
	int		i;
	char	buf[1024];
	char	*str;

	if ((fd = open(file, O_RDONLY)) < 0)
		return (exec_print_error(file));
	str = ft_strnew(0);
	while ((i = read(fd, &buf, 1023)))
	{
		buf[i] = '\0';
		str = ft_strjoin_free(str, buf, 1);
	}
	close(fd);
	if (pipe(pipefd) < 0)
		return (exec_print_error(NULL));
	dup2(pipefd[0], 0);
	write(pipefd[1], str, ft_strlen(str));
	close(pipefd[1]);
	close(pipefd[0]);
	free(str);
	return (0);
}

void		exec_fill_fifo_two_left(char *str, int fd)
{
	int		pipefd[2];
	char	buf[1024];
	int		i;

	if (pipe(pipefd) < 0)
		exit(-1);
	dup2(fd, 0);
	while (1)
	{
		write(1, "> ", 2);
		i = read(0, &buf, 1023);
		buf[i - 1] = '\0';
		if (ft_strequ(buf, str))
			break ;
		else
		{
			write(pipefd[1], buf, i - 1);
			write(pipefd[1], "\n", 1);
		}
	}
	dup2(pipefd[0], 0);
	close(pipefd[1]);
	close(pipefd[0]);
}

void		exec_fill_fifo_three_left(char *str)
{
	int		pipefd[2];

	if (pipe(pipefd) < 0)
		exit(-1);
	dup2(pipefd[0], 0);
	write(pipefd[1], str, ft_strlen(str));
	write(pipefd[1], "\n", 1);
	close(pipefd[1]);
	close(pipefd[0]);
}

int			exec_fill_fifo(t_attr *attr, int fd)
{
	int		return_value;

	return_value = 0;
	while (attr)
	{
		if (attr->spec.bits.l)
			return_value = exec_fill_fifo_one_left(attr->file);
		else if (attr->spec.bits.ll)
			exec_fill_fifo_two_left(attr->file, fd);
		else if (attr->spec.bits.lll)
			exec_fill_fifo_three_left(attr->file);
		if (return_value == -1)
			return (-1);
		attr = attr->next;
	}
	return (0);
}
