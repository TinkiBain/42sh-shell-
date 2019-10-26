/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggwin-go <ggwin-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/16 17:38:16 by ggwin-go          #+#    #+#             */
/*   Updated: 2019/10/24 18:11:04 by ggwin-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

extern t_opt	g_opt;

static void		print_options(int is_minus_o)
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
		ft_printf(format, (g_opt.enable_color) ? "+" : "-", "color");
		ft_printf(format, (g_opt.emacs_mode) ? "+" : "-", "emacs");
		ft_printf(format, (g_opt.history) ? "+" : "-", "history");
		ft_printf(format, (g_opt.noclobber) ? "+" : "-", "noclobber");
		ft_printf(format, (g_opt.promptsp) ? "+" : "-", "promptsp");
		ft_printf(format, (g_opt.vi_mode) ? "+" : "-", "vi");
	}
}

static void		handle_set_minus_o(const char **av)
{
	if (!*(++av))
		print_options(1);
	else
	{
		if (ft_strequ(*(av), "vi"))
		{
			g_opt.vi_mode = 1;
			g_opt.emacs_mode = 0;
		}
		else if (ft_strequ(*(av), "emacs"))
		{
			g_opt.emacs_mode = 1;
			g_opt.vi_mode = 0;
		}
		else if (ft_strequ(*(av), "color"))
			g_opt.enable_color = 1;
		else if (ft_strequ(*(av), "noclobber"))
			g_opt.noclobber = 1;
		else if (ft_strequ(*(av), "history"))
			g_opt.history = 1;
		else if (ft_strequ(*(av), "promptsp"))
			g_opt.promptsp = 1;
		set_var_shellopts();
	}
}

static void		handle_set_arg(const char **av)
{
	if (ft_strequ(*av, "-p"))
		print_var_names();
	else if (ft_strequ(*(av), "-o"))
		handle_set_minus_o(av);
	else if (ft_strequ(*(av), "+o"))
	{
		if (!*(++av))
			print_options(0);
		else
		{
			if (ft_strequ(*(av), "vi"))
				g_opt.vi_mode = 0;
			else if (ft_strequ(*(av), "emacs"))
				g_opt.emacs_mode = 0;
			else if (ft_strequ(*(av), "color"))
				g_opt.enable_color = 0;
			else if (ft_strequ(*(av), "noclobber"))
				g_opt.noclobber = 0;
			else if (ft_strequ(*(av), "history"))
				g_opt.history = 0;
			else if (ft_strequ(*(av), "promptsp"))
				g_opt.promptsp = 0;
			set_var_shellopts();
		}
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
			print_vars(1);
		else
			while (*av)
				handle_set_arg(av++);
	}
	return (0);
}
