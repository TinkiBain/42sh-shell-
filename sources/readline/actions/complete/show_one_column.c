/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_one_column.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelisan <gmelisan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 19:12:39 by gmelisan          #+#    #+#             */
/*   Updated: 2019/09/04 19:23:23 by gmelisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "actions.h"

void		show_one_column(char **arr, int n)
{
	extern t_opt	g_opt;
	int				i;

	ft_fdprintf(g_opt.rl_out, "\r\n");
	i = 0;
	while (i < n)
	{
		ft_fdprintf(g_opt.rl_out, "%s\r\n", arr[i]);
		i++;
	}
}
