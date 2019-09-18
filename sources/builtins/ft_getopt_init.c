/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getopt_init.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelisan <gmelisan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 15:10:26 by gmelisan          #+#    #+#             */
/*   Updated: 2019/09/16 15:40:15 by gmelisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "defs.h"
#include "xfuncs.h"
#include "ft_getopt.h"

void	ft_getopt_init(char *cmd_name)
{
	t_string	str;

	str = str_xcopy(g_project_name);
	str_xaddback(&str, ": ", 2);
	str_xaddback(&str, cmd_name, ft_strlen(cmd_name));
	str_xaddback(&str, ": ", 2);
	g_opterrpref = str.s;
}
