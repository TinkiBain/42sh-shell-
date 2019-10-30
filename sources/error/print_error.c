/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelisan <gmelisan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 22:35:39 by gmelisan          #+#    #+#             */
/*   Updated: 2019/10/30 20:07:20 by gmelisan         ###   ########.fr       */
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

void			str_xaddnback(t_string *str, int n, ...)
{
	va_list ap;
	char	*arg;

	va_start(ap, n);
	while (--n >= 0)
	{
		arg = va_arg(ap, char *);
		str_xaddback(str, arg, ft_strlen(arg));
	}
	va_end(ap);
}

void			print_error(const char *info, const char *msg)
{
	t_string	info_formatted;
	t_string	tmp;
	char		*p;

	tmp = str_xcreate(0);
	str_xaddnback(&tmp, 2, g_project_name, ": ");
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
		str_xaddnback(&tmp, 2, info_formatted.s, ": ");
		str_delete(&info_formatted);
	}
	str_xaddnback(&tmp, 2, msg, "\n\r");
	write(STDERR, tmp.s, tmp.len);
	loginfo("! Error: %s (%s)", msg, info);
	str_delete(&tmp);
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

	reserve_sem(SEMPRINT, 1, 1);
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
