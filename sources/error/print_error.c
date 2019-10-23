/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggwin-go <ggwin-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 22:35:39 by gmelisan          #+#    #+#             */
/*   Updated: 2019/10/23 23:10:30 by ggwin-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "xfuncs.h"
#include "error.h"
#include "sem.h"

extern t_opt	g_opt;
extern int		g_line_num;

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
	t_string	info_formatted;
	t_string	tmp;
	char		*p;

	// reserve_sem(SEMPRINT, 1);
	tmp = str_xcreate(1024);
	str_xaddback(&tmp, g_project_name, ft_strlen(g_project_name));
	str_xaddback(&tmp, ": ", 2);
	if (g_opt.rl_gnl != 0)
	{
		str_xaddback(&tmp, "line ", 5);
		p = ft_itoa(g_line_num);
		str_xaddback(&tmp, p, ft_strlen(p));
		ft_strdel(&p);
		str_xaddback(&tmp, ": ", 2);
	}
	if (info)
	{
		info_formatted = format_info(info);
		str_xaddback(&tmp, info_formatted.s, info_formatted.len);
		str_xaddback(&tmp, ": ", 2);
		str_delete(&info_formatted);
	}
	str_xaddback(&tmp, msg, ft_strlen(msg));
	str_xaddback(&tmp, "\n\r", 2);
	write(STDERR, tmp.s, tmp.len);
	loginfo("! Error: %s (\"%s\")", msg, info);
	str_delete(&tmp);
	// release_sem(SEMPRINT, 1);
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
	va_list		ap;

	reserve_sem(SEMPRINT, 1);
	ft_fdprintf(STDERR, "%s: ", g_project_name);
	if (g_opt.rl_gnl != 0)
		ft_fdprintf(STDERR, "line %d: ", g_line_num);
	va_start(ap, msg);
	ft_vfdprintf(STDERR, msg, ap);
	va_end(ap);
	va_start(ap, msg);
	loginfo_vaarg(msg, ap);
	va_end(ap);
	release_sem(SEMPRINT, 1);
}
