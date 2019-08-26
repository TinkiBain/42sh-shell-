/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash_print.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wtalea <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/24 16:54:25 by wtalea            #+#    #+#             */
/*   Updated: 2019/08/26 17:12:38 by wtalea           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hash.h"

static	int			max_len_count(int count, t_hash *table_count[count])
{
	int		i;
	int		count_len;

	i = 0;
	count_len = 0;
	while (i < (count))
	{
		if (ft_intlen(table_count[i]->hash_count) > count_len)
			count_len = ft_intlen(table_count[i]->hash_count);
		++i;
	}
	return (count_len);
}

static	void		find_in_one_basket(t_hash *table, int count,
		t_hash *table_count[count], int *i)
{
	while (table)
	{
		if (table->hash_on)
		{
			table_count[*i] = table;
			++(*i);
		}
		table = table->next;
	}
}

static	void		find_hash_use(int count)
{
	extern	t_hash	**g_table;
	int				i;
	int				j;
	t_hash			*table_count[count];

	i = 0;
	j = 0;
	while (i < HASH_LEN)
		find_in_one_basket(*(g_table + i++), count, table_count, &j);
	i = max_len_count(count, table_count);
	hash_print_new(count, table_count, i);
}

void				hash_print(void)
{
	int				count;

	count = 0;
	if ((count = count_hash_on()) > 0)
		find_hash_use(count);
	else
		hash_empty();
}
