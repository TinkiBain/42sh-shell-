/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect_error.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwisoky <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 20:22:52 by dwisoky           #+#    #+#             */
/*   Updated: 2019/08/06 21:13:07 by dwisoky          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"
#include "defs.h"

int		redirect_error_file(char *file)
{
	ft_putstr_fd(PROJECT_NAME ": ", 2);
	ft_putstr_fd(file, 2);
	ft_putstr_fd(": No such file or directory\n", 2);
	return (-1);
}

int		redirect_error_fd(int fd)
{
	ft_putstr_fd(PROJECT_NAME ": ", 2);
	ft_putnbr_fd(fd, 2);
	ft_putstr_fd(": Bad file descriptor\n", 2);
	return (-1);
}

int		redirect_error_permission(char *file)
{
	ft_putstr_fd(PROJECT_NAME ": ", 2);
	ft_putstr_fd(file, 2);
	ft_putstr_fd(": Permission denied\n", 2);
	return (-1);
}

int		redirect_error_direct(char *file)
{
	ft_putstr_fd(PROJECT_NAME ": ", 2);
	ft_putstr_fd(file, 2);
	ft_putstr_fd(": Is a directory\n", 2);
	return (-1);
}

int		redirect_error_long_name(char *file)
{
	ft_putstr_fd(PROJECT_NAME ": ", 2);
	ft_putstr_fd(file, 2);
	ft_putstr_fd(": File name too long\n", 2);
	return (-1);
}

int		redirect_error_open(char *file)
{
	ft_putstr_fd(PROJECT_NAME ": ", 2);
	ft_putstr_fd(file, 2);
	ft_putstr_fd(": open error\n", 2);
	return (-1);
}
