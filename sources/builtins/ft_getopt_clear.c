/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getopt_clear.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelisan <gmelisan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 15:38:04 by gmelisan          #+#    #+#             */
/*   Updated: 2019/09/16 15:38:34 by gmelisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include "ft_getopt.h"

void	ft_getopt_clear(void)
{
	g_optarg = NULL;
	g_optind = 1;
	g_optpos = 1;
	ft_strdel(&g_opterrpref);
}
