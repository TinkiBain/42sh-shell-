/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_help.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelisan <gmelisan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 18:45:31 by gmelisan          #+#    #+#             */
/*   Updated: 2019/10/24 19:10:34 by gmelisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"
#include "colors.h"

int		ft_help(void)
{
	char *msg;

	msg =
		COLOR_GREEN "Welcome to " PROJECT_NAME COLOR_EOC "\n"
		"Version " VERSION "\n"
		"\n"
		"Prompt help ($PS1):\n"
		"%s - shell name\n"
		"%v - version\n"
		"%w - current directory (with ~ for HOME)\n"
		"%{color}, where {color} is one of (black, red, green, yellow, "
		"blue, purple, cyan, white, grey) - enable color\n"
		"%eoc - disable color\n"
		"\n"
		"Made by ggwin-go, dwisoky, jterry, gmelisan and wtalea\n";
	ft_putstr(msg);
	return (0);
}
