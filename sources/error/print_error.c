/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelisan <gmelisan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 22:35:39 by gmelisan          #+#    #+#             */
/*   Updated: 2019/10/13 17:02:48 by gmelisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "xfuncs.h"
#include "error.h"
#include "sem.h"

static t_string	format_info(const char *info)
{
	t_string	str;
	int			i;
	char		c;

	str = str_xcopy(info);
	i = -1;
	while ((c = str_get(str, ++i)))
	{
		if (c == '\n')
		{
			str_remove(&str, i, 1);
			str_insert(&str, i, "\\n", 2);
		}
	}
	if (!ft_strequ(str.s, info))
	{
		str_insert(&str, 0, "'", 1);
		str_insert(&str, str.len, "'", 1);
	}
	return (str);
}

void			print_error(const char *info, const char *msg)
{
	extern t_opt	g_opt;
	extern int		g_line_num;
	t_string		info_formatted;

	reserve_sem(1);
	ft_fdprintf(STDERR, "%s: ", g_project_name);
	if (g_opt.rl_gnl != 0)
		ft_fdprintf(STDERR, "line %d: ", g_line_num);
	if (info)
	{
		info_formatted = format_info(info);
		ft_fdprintf(STDERR, "%s: ", info_formatted.s);
		str_delete(&info_formatted);
	}
	ft_fdprintf(STDERR, "%s\n\r", msg);
	loginfo("! Error: %s (\"%s\")", msg, info);
	release_sem(1);
}

void			print_error_exit(const char *info, const char *msg,
														const int code)
{
	print_error(info, msg);
	logclose();
	exit(code);
}

void			print_error_vaarg(const char *msg, ...)
{
	va_list			ap;
	extern t_opt	g_opt;
	extern int		g_line_num;

	reserve_sem(1);
	ft_fdprintf(STDERR, "%s: ", g_project_name);
	if (g_opt.rl_gnl != 0)
		ft_fdprintf(STDERR, "line %d: ", g_line_num);
	va_start(ap, msg);
	ft_vfdprintf(STDERR, msg, ap);
	va_end(ap);
	va_start(ap, msg);
	loginfo_vaarg(msg, ap);
	va_end(ap);
	release_sem(1);
}
