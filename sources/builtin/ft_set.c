/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggwin-go <ggwin-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/16 17:38:16 by ggwin-go          #+#    #+#             */
/*   Updated: 2019/08/26 16:18:42 by ggwin-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

extern struct s_rl_options	g_rl_options;

static void					print_plus_options(void)
{
	char	*name;
	char	*val;
	char	*format;

	format = "set %so %s\n";
	name = "vi";
	val = (g_rl_options.vi_mode) ? "+" : "-";
	ft_printf(format, val, name);
	name = "color";
	val = (g_rl_options.enable_color) ? "+" : "-";
	ft_printf(format, val, name);
}

static void					print_minus_options(void)
{
	char	*name;
	char	*val;
	char	*format;

	format = "%-15s\t%s\n";
	name = "vi";
	val = (g_rl_options.vi_mode) ? "on" : "off";
	ft_printf(format, name, val);
	name = "color";
	val = (g_rl_options.enable_color) ? "on" : "off";
	ft_printf(format, name, val);
}

static void					unset_option(const char **av)
{
	if (ft_strequ(*(av), "vi"))
		g_rl_options.vi_mode = 0;
	if (ft_strequ(*(av), "color"))
		g_rl_options.enable_color = 0;
}

static void					handle_set_arg(const char **av)
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
				g_rl_options.vi_mode = 1;
			if (ft_strequ(*(av), "color"))
				g_rl_options.enable_color = 1;
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

int							ft_set(const char **av)
{
	extern	char	**g_var;
	extern	char	**environ;

	if (!g_var)
		return (1);
	if (av)
	{
		while (*av)
		{
			if (!*av)
				print_all_vars();
			else
				handle_set_arg(av);
			++av;
		}
	}
	return (0);
}
