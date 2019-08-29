/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del_hash.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wtalea <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/02 15:00:19 by wtalea            #+#    #+#             */
/*   Updated: 2019/08/29 17:20:18 by wtalea           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hash.h"
#include <stdio.h>

extern	t_hash	**g_table;
extern	char	**g_cmd_names;

void	del_hash(void)
{
	int				i;
	t_hash			*cp;

	i = 0;
	cp = NULL;
	while (i < HASH_LEN)
	{
		if (g_table && *((g_table) + i))
			while (*((g_table) + i))
			{
				cp = (*((g_table) + i))->next;
				ft_strdel(&(*((g_table) + i))->path);
				ft_strdel(&(*((g_table) + i))->name);
				ft_free_double_ptr_arr((void ***)&(*(g_table + i))->flags_args);
				free(*((g_table) + i));
				*((g_table) + i) = cp;
			}
		++i;
	}
	free(g_table);
	free(g_cmd_names);
	g_table = NULL;
	g_cmd_names = NULL;
}
