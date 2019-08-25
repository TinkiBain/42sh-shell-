/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_hash_on.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wtalea <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/25 16:34:37 by wtalea            #+#    #+#             */
/*   Updated: 2019/08/25 16:41:20 by wtalea           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hash.h"

static	void	count_table(t_hash *table, int *count)
{
	while (table)
	{
		if (table->hash_on)
			++(*count);
		table = table->next;
	}
}

int				count_hash_on(void)
{
	extern	t_hash	**g_table;
	int				i;
	int				count;

	i = 0;
	count = 0;
	while (i < HASH_LEN)
	{
		count_table(*(g_table + i), &count);
		++i;
	}
	return (0);
}
