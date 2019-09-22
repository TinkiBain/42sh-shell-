/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggwin-go <ggwin-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 22:35:39 by gmelisan          #+#    #+#             */
/*   Updated: 2019/09/22 22:02:53 by gmelisan         ###   ########.fr       */
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
		str_insert(&str, 0, "$'", 2);
		str_insert(&str, str.len, "'", 1);
	}
	return (str);
}

void		print_error(const char *msg, const char *info)
{
	extern t_opt	g_opt;
	extern int		g_line_num;
	t_string		info_formatted;

	reserve_sem();
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
	release_sem();
}

void	print_error_exit(const char *msg, const char *info, const int code)
{
	print_error(msg, info);
	logclose();
	exit(code);
}
