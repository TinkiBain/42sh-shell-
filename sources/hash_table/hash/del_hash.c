/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del_hash.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wtalea <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/02 15:00:19 by wtalea            #+#    #+#             */
/*   Updated: 2019/08/02 15:47:39 by wtalea           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hash.h"
#include <stdio.h>

void	del_hash(t_hash ***table)
{
	int		i;
	t_hash	*cp;

	i = 0;
	cp = NULL;
	while (i < HASH_LEN)
	{
		if (*((*table) + i))
			while (*((*table) + i))
			{
				cp = (*((*table) + i))->next;
				free((*((*table) + i))->path);
				(*((*table) + i))->path = NULL;
				free((*((*table) + i))->name);
				(*((*table) + i))->name = NULL;
				free(*((*table) + i));
				*((*table) + i) = cp;
			}
		++i;
	}
	free(*table);
	*table = NULL;
}
