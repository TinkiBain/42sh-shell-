/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_help.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jterry <jterry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 18:45:31 by gmelisan          #+#    #+#             */
/*   Updated: 2019/10/28 17:58:31 by gmelisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"
#include "colors.h"

int		ft_help(void)
{
	ft_putstr(
		COLOR_GREEN_BOLD "Welcome to " PROJECT_NAME COLOR_EOC "\n"
		"Version " VERSION "\n"
		"\n"
		"Prompt help ($PS1):\n"
		"%u - username\n"
		"%s - shell name\n"
		"%v - version\n"
		"%w - current directory (with ~ for HOME)\n"
		"%{color}, where {color} is one of (black, red, green, yellow, "
		"blue, purple, cyan, white, grey) - enable color\n"
		"%eoc - disable color\n"
		"\n"
		"Made by " COLOR_BOLD "ggwin-go" COLOR_EOC", "
		COLOR_BOLD "dwisoky" COLOR_EOC ", "
		COLOR_BOLD "jterry" COLOR_EOC ", "
		COLOR_BOLD "gmelisan" COLOR_EOC ", "
		"and " COLOR_BOLD "wtalea" COLOR_EOC "\n\n");
	return (0);
}
