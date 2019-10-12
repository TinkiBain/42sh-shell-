/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alias_func_size.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wtalea <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 16:43:31 by wtalea            #+#    #+#             */
/*   Updated: 2019/10/12 17:37:49 by wtalea           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hash.h"

extern	t_alias	*g_alias;

#if 0
int		func_size_list(g_alias *func)
{
	int		i;

	i = 0;
	while (func)
	{
		if (!get_bin(func->head))
			++i;
		func = func->next;
	}
	return (i);
}
#endif

int		alias_size_list(t_alias *alias)
{
	int		i;

	i = 0;
	while (alias)
	{
		if (!get_bin(alias->head))
			++i;
		alias = alias->next;
	}
	return (i);
}
