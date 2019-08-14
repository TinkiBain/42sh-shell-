/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect_error.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwisoky <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 20:22:52 by dwisoky           #+#    #+#             */
/*   Updated: 2019/08/12 16:12:56 by dwisoky          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"
#include "defs.h"

int		redirect_error_range_fd(void)
{
	ft_putstr_fd(PROJECT_NAME
			": file descriptor out of range: ambiguous redirect\n", 2);
	return (-1);
}

int		redirect_error_ambiguous(char *file)
{
	ft_putstr_fd(PROJECT_NAME ": ", 2);
	ft_putstr_fd(file, 2);
	ft_putstr_fd(": ambiguous redirect\n", 2);
	return (-1);
}

int		redirect_error_fd(int fd)
{
	ft_putstr_fd(PROJECT_NAME ": ", 2);
	ft_putnbr_fd(fd, 2);
	ft_putstr_fd(": Bad file descriptor\n", 2);
	return (-1);
}

int		redirect_error_open(char *file)
{
	ft_putstr_fd(PROJECT_NAME ": ", 2);
	perror(file);
	return (-1);
}

int		redirect_error_dup(int fd)
{
	ft_putstr_fd(PROJECT_NAME ": ", 2);
	ft_putnbr_fd(fd, 2);
	perror(NULL);
	return (-1);
}
