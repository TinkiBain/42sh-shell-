/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del_hash.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wtalea <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/02 15:00:19 by wtalea            #+#    #+#             */
/*   Updated: 2019/08/06 15:23:21 by wtalea           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hash.h"
#include <stdio.h>

void	del_hash(void)
{
	int				i;
	t_hash			*cp;
	extern	t_hash	**g_table;

	i = 0;
	cp = NULL;
	while (i < HASH_LEN)
	{
		if (*((g_table) + i))
			while (*((g_table) + i))
			{
				cp = (*((g_table) + i))->next;
				free((*((g_table) + i))->path);
				(*((g_table) + i))->path = NULL;
				free((*((g_table) + i))->name);
				(*((g_table) + i))->name = NULL;
				free(*((g_table) + i));
				*((g_table) + i) = cp;
			}
		++i;
	}
	free(g_table);
	g_table = NULL;
}
