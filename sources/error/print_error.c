/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelisan <gmelisan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 22:35:39 by gmelisan          #+#    #+#             */
/*   Updated: 2019/09/03 22:51:01 by gmelisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error.h"

void		print_error(const char *msg, const char *info)
{
	ft_fdprintf(STDERR, "%s: ", g_project_name);
	if (info)
		ft_fdprintf(STDERR, "%s: ", info);
	ft_fdprintf(STDERR, "%s\n", msg);
	loginfo("! Error: %s (\"%s\")", msg, info);
}

void		print_error_ext(const char *msg, const char *info1, const char *info2)
{
	ft_fdprintf(STDERR, "%s: ", g_project_name);
	if (info1)
		ft_fdprintf(STDERR, "%s: ", info1);
	if (info2)
		ft_fdprintf(STDERR, "%s: ", info2);
	ft_fdprintf(STDERR, "%s\n", msg);
	loginfo("! Error %s (\"%s\", \"%s\")", msg, info1, info2);
}

void		print_error_exit(const char *msg, const char *info, const int code)
{
	print_error(msg, info);
	logclose();
	exit(code);
}
