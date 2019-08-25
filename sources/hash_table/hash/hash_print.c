/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash_print.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wtalea <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/24 16:54:25 by wtalea            #+#    #+#             */
/*   Updated: 2019/08/24 17:13:26 by wtalea           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hash.h"

static	void	hash_print_count(t_hash *table)
{

}

static	void	find_in_one_basket(t_hash *table, int *count)
{
	while (table)
	{
		if (table->hash_on)
		{
			hash_print_count(table);
			if (!*count)
				hash_print_new();
			++(*count);
		}
		table = table->next;
	}
}

static	int		find_hash_use(void)
{
	extern	t_hash	**g_table;
	int				count;
	int				i;

	count = 0;
	i = 0;
	while (i < HASH_LEN)
		find_in_one_basket(*(g_table + i++), &count);
	return (count);
}

void		hash_print(void)
{
	int				count;

	count = 0;
	count = find_hash_use();
}
