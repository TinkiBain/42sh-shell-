/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelisan <gmelisan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/07 21:16:01 by gmelisan          #+#    #+#             */
/*   Updated: 2019/10/30 20:23:42 by gmelisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int			max_int(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

int			cmp_pstring(const void *a, const void *b)
{
	return (ft_strcmp(((t_string *)a)->s,
						((t_string *)b)->s));
}

int			ft_putint(int c)
{
	extern t_opt	g_opt;

	write(g_opt.rl_out, &c, 1);
	return (0);
}
