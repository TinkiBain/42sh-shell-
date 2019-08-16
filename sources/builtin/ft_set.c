/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggwin-go <ggwin-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/16 17:38:16 by ggwin-go          #+#    #+#             */
/*   Updated: 2019/08/16 23:12:33 by ggwin-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

int			ft_set(const char **av)
{
	extern	char	**g_var;
	char			**tmp;

	tmp = g_var;
	if (!g_var)
		return (1);
	if (av && !*av)
		while (*tmp)
		{
			ft_putendl(*(tmp++));
		}
	// else
	// 	while (*av)
	// 	{
	// 		set_var(*av, &tmp, 0);
	// 		++av;
	// 	}
	return (0);
}
