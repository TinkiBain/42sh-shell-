/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jterry <jterry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/16 17:38:16 by ggwin-go          #+#    #+#             */
/*   Updated: 2019/11/02 01:17:15 by jterry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

extern t_opt					g_opt;
extern char						**g_var;

#define FLAG_DEFAULT			0
#define FLAG_PRINT_VARS_NAME	1
#define FLAG_PRINT_OPTS			2
#define FLAG_SET_OPT			4

static void						print_options(int is_minus_o)
{
	char	*format;

	format = (is_minus_o) ? "%-15s\t%s\n" : "set %so %s\n";
	if (is_minus_o)
	{
		ft_printf(format, "color", (g_opt.enable_color) ? "on" : "off");
		ft_printf(format, "emacs", (g_opt.emacs_mode) ? "on" : "off");
		ft_printf(format, "history", (g_opt.history) ? "on" : "off");
		ft_printf(format, "noclobber", (g_opt.noclobber) ? "on" : "off");
		ft_printf(format, "promptsp", (g_opt.promptsp) ? "on" : "off");
		ft_printf(format, "vi", (g_opt.vi_mode) ? "on" : "off");
	}
	else
	{
		ft_printf(format, (g_opt.enable_color) ? "-" : "+", "color");
		ft_printf(format, (g_opt.emacs_mode) ? "-" : "+", "emacs");
		ft_printf(format, (g_opt.history) ? "-" : "+", "history");
		ft_printf(format, (g_opt.noclobber) ? "-" : "+", "noclobber");
		ft_printf(format, (g_opt.promptsp) ? "-" : "+", "promptsp");
		ft_printf(format, (g_opt.vi_mode) ? "-" : "+", "vi");
	}
}

static void						handle_set_opt(const char *opt, char sign)
{
	if (ft_strequ(opt, "vi"))
	{
		g_opt.vi_mode = (sign == '-') ? 1 : 0;
		g_opt.emacs_mode = (sign == '-') ? 0 : g_opt.emacs_mode;
	}
	else if (ft_strequ(opt, "emacs"))
	{
		g_opt.emacs_mode = (sign == '-') ? 1 : 0;
		g_opt.vi_mode = (sign == '-') ? 0 : g_opt.vi_mode;
	}
	else if (ft_strequ(opt, "color"))
		g_opt.enable_color = (sign == '-') ? 1 : 0;
	else if (ft_strequ(opt, "noclobber"))
		g_opt.noclobber = (sign == '-') ? 1 : 0;
	else if (ft_strequ(opt, "history"))
		g_opt.history = (sign == '-') ? 1 : 0;
	else if (ft_strequ(opt, "promptsp"))
		g_opt.promptsp = (sign == '-') ? 1 : 0;
	set_var_shellopts();
}

static void						handle_set_arg(const char **av, int flag)
{
	char	sign;

	while (*av)
	{
		if (((sign = **av) == '-' || sign == '+') && ft_strchr(*(av), 'o'))
		{
			if (*(av + 1) && **(av + 1) != '-' && **(av + 1) != '+')
				handle_set_opt(*(++av), sign);
			else if (flag == FLAG_PRINT_OPTS)
				print_options((sign == '-') ? 1 : 0);
		}
		++av;
	}
}

static int						local_check_flags(const char **av,
												int *flag, char *c)
{
	char		*tmp;

	while ((tmp = (char *)*av))
	{
		if (*tmp == '-' || *tmp == '+')
		{
			while (*(++tmp))
			{
				if (*tmp == 'o')
				{
					if (*(av + 1) && **(av + 1) != '-' && **(av + 1) != '+')
						*flag = FLAG_SET_OPT;
					else if (*flag < FLAG_PRINT_OPTS)
						*flag = FLAG_PRINT_OPTS;
				}
				else if (*tmp == 'p')
					*flag = (*flag == 0) ? FLAG_PRINT_VARS_NAME : *flag;
				else if ((*c = *tmp) == *tmp)
					return (1);
			}
		}
		++av;
	}
	return (0);
}

int								ft_set(const char **av)
{
	int			flag;
	char		c;

	flag = 0;
	if (!g_var)
		return (1);
	if (!*av)
	{
		print_vars(1);
		return (0);
	}
	if (local_check_flags(av, &flag, &c))
	{
		print_error_vaarg("set: -%c: invalid option\n"
						"set: usage: set [-p] [-o option]\n", c);
		return (2);
	}
	if (flag == FLAG_SET_OPT || flag == FLAG_PRINT_OPTS)
		handle_set_arg(av, flag);
	else if (flag == FLAG_PRINT_VARS_NAME)
		print_var_names();
	return (0);
}
