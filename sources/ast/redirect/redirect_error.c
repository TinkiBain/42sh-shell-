/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect_error.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggwin-go <ggwin-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 20:22:52 by dwisoky           #+#    #+#             */
/*   Updated: 2019/10/09 17:01:12 by gmelisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"
#include "defs.h"
#include "error.h"

int		redirect_error_range_fd(void)
{
	print_error("file descriptor out of range", "ambiguous redirect");
	return (-1);
}

int		redirect_error_ambiguous(char *file)
{
	print_error(file, "ambiguous redirect");
	return (-1);
}

int		redirect_error_fd(int fd)
{
	print_error_vaarg("%d: Bad file descriptor\n", fd);
	return (-1);
}

int		redirect_error_open(char *file)
{
	print_error_vaarg("");
	perror(file);
	return (-1);
}

int		redirect_error_dup(int fd)
{
	print_error_vaarg("%d: ", fd);
	perror(NULL);
	return (-1);
}
