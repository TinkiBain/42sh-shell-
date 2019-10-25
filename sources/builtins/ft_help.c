/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_help.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jterry <jterry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 18:45:31 by gmelisan          #+#    #+#             */
/*   Updated: 2019/10/25 16:48:49 by jterry           ###   ########.fr       */
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
		COLOR_BOLD "Made by ggwin-go, dwisoky, jterry, gmelisan and wtalea\n\n"
		COLOR_EOC;
	ft_putstr(msg);
	return (0);
}
