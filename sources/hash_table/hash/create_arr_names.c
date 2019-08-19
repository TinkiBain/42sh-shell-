/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_arr_names.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wtalea <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/19 15:34:35 by wtalea            #+#    #+#             */
/*   Updated: 2019/08/19 16:34:58 by wtalea           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hash.h"

static	void	add_names(t_hash *table, char **names, int *j)
{
	while (table)
	{
		*(names + *j) = table->name;
		++(*j);
		table = table->next;
	}
}

static	void	sort_arr_names(int len)
{
	extern	char	**g_prog_names;

	ft_arr_str_qsort(g_prog_names, len);
}

void			create_arr_names(void)
{
	extern	char	**g_prog_names;
	extern	int		g_prog_names_count;
	extern	t_hash	**g_table;
	int				i;
	int				j;

	i = 0;
	j = 0;
	if (g_prog_names_count)
	{
		if ((g_prog_names = (char **)ft_memalloc(sizeof(char *) *
						(g_prog_names_count + 1))) == NULL)
			die();
		while (i < HASH_LEN)
		{
			if (*(g_table + i))
				add_names(*(g_table + i), g_prog_names, &j);
			++i;
		}
		sort_arr_names(g_prog_names_count);
	}
}
