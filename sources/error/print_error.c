/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggwin-go <ggwin-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 22:35:39 by gmelisan          #+#    #+#             */
/*   Updated: 2019/09/16 14:45:28 by dwisoky          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error.h"

/* static char	*get_str_line_num(void) */
/* { */
/* 	extern int	g_line_num; */
/* 	char		*p; */
/* 	static char	res[32]; */

/* 	ft_bzero(res, 32); */
/* 	if (!(p = ft_itoa(g_line_num))) */
/* 		die(); */
/* 	ft_memcpy(res, "line ", 5); */
/* 	ft_memcpy(res + 5, p, ft_strlen(p)); */
/* 	ft_strdel(&p); */
/* 	return (res); */
/* } */

void		print_error(const char *msg, const char *info)
{
	extern t_opt	g_opt;
	extern int		g_line_num;

	ft_fdprintf(STDERR, "%s: ", g_project_name);
	if (g_opt.rl_gnl != 0)
		ft_fdprintf(STDERR, "line %d: ", g_line_num);
	if (info)
		ft_fdprintf(STDERR, "%s: ", info);
	ft_fdprintf(STDERR, "%s\n\r", msg);
	loginfo("! Error: %s (\"%s\")", msg, info);
}

void	print_error_exit(const char *msg, const char *info, const int code)
{
	print_error(msg, info);
	logclose();
	exit(code);
}
