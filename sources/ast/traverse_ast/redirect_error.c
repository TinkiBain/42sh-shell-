/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect_error.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggwin-go <ggwin-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 20:22:52 by dwisoky           #+#    #+#             */
/*   Updated: 2019/08/29 17:27:52 by ggwin-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"
#include "defs.h"

int		redirect_error_range_fd(void)
{
	ft_putstr_fd(g_project_name, 2);
	ft_putstr_fd(": file descriptor out of range: ambiguous redirect\n", 2);
	return (-1);
}

int		redirect_error_ambiguous(char *file)
{
	ft_putstr_fd(g_project_name, 2);
	ft_putstr_fd(": ", 2);
	ft_putstr_fd(file, 2);
	ft_putstr_fd(": ambiguous redirect\n", 2);
	return (-1);
}

int		redirect_error_fd(int fd)
{
	ft_putstr_fd(g_project_name, 2);
	ft_putstr_fd(": ", 2);
	ft_putnbr_fd(fd, 2);
	ft_putstr_fd(": Bad file descriptor\n", 2);
	return (-1);
}

int		redirect_error_open(char *file)
{
	ft_putstr_fd(g_project_name, 2);
	ft_putstr_fd(": ", 2);
	perror(file);
	return (-1);
}

int		redirect_error_dup(int fd)
{
	ft_putstr_fd(g_project_name, 2);
	ft_putstr_fd(": ", 2);
	ft_putnbr_fd(fd, 2);
	perror(NULL);
	return (-1);
}
