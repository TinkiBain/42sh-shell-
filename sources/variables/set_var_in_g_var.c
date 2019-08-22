/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_var_in_g_var.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggwin-go <ggwin-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/22 17:33:28 by ggwin-go          #+#    #+#             */
/*   Updated: 2019/08/22 17:33:56 by ggwin-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

int			set_var_in_g_var(const char **av)
{
	extern	char	**g_var;

	if (!g_var)
		return (1);
	while (*av)
	{
		set_var(*av, &g_var, 0);
		++av;
	}
	return (0);
}
