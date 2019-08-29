/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggwin-go <ggwin-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/16 17:38:16 by ggwin-go          #+#    #+#             */
/*   Updated: 2019/08/28 15:57:43 by ggwin-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

extern t_opt	g_opt;

static void		print_plus_options(void)
{
	char	*name;
	char	*val;
	char	*format;

	format = "set %so %s\n";
	name = "vi";
	val = (g_opt.vi_mode) ? "+" : "-";
	ft_printf(format, val, name);
	name = "color";
	val = (g_opt.enable_color) ? "+" : "-";
	ft_printf(format, val, name);
	name = "noclobber";
	val = (g_opt.noclobber) ? "+" : "-";
	ft_printf(format, val, name);
}

static void		print_minus_options(void)
{
	char	*name;
	char	*val;
	char	*format;

	format = "%-15s\t%s\n";
	name = "vi";
	val = (g_opt.vi_mode) ? "on" : "off";
	ft_printf(format, name, val);
	name = "color";
	val = (g_opt.enable_color) ? "on" : "off";
	ft_printf(format, name, val);
	name = "noclobber";
	val = (g_opt.noclobber) ? "on" : "off";
	ft_printf(format, name, val);
}

static void		unset_option(const char **av)
{
	if (ft_strequ(*(av), "vi"))
		g_opt.vi_mode = 0;
	else if (ft_strequ(*(av), "color"))
		g_opt.enable_color = 0;
	else if (ft_strequ(*(av), "noclobber"))
		g_opt.noclobber = 0;
	set_var_shellopts();
}

static void		handle_set_arg(const char **av)
{
	if (ft_strequ(*av, "-p"))
		print_var_names();
	else if (ft_strequ(*(av), "-o"))
	{
		if (!*(++av))
			print_minus_options();
		else
		{
			if (ft_strequ(*(av), "vi"))
				g_opt.vi_mode = 1;
			else if (ft_strequ(*(av), "color"))
				g_opt.enable_color = 1;
			else if (ft_strequ(*(av), "noclobber"))
				g_opt.noclobber = 1;
			set_var_shellopts();
		}
	}
	else if (ft_strequ(*(av), "+o"))
	{
		if (!*(++av))
			print_plus_options();
		else
			unset_option(av);
	}
}

int				ft_set(const char **av)
{
	extern char	**g_var;

	if (!g_var)
		return (1);
	if (av)
	{
		if (!*av)
			print_all_vars();
		else
			while (*av)
				handle_set_arg(av++);
	}
	return (0);
}
