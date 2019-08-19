/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_arr_names.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wtalea <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/19 15:34:35 by wtalea            #+#    #+#             */
/*   Updated: 2019/08/19 17:54:57 by wtalea           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hash.h"
#include <stdio.h>

/*static void	check_god(char **str)
{
	int		i;

	i = 0;
	while (*str)
	{
//		printf("%s\n", *str);
		++i;
		++(str);
	}
	printf("%d\n", i);
}*/

char			**g_cmd_names;

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
	ft_arr_str_qsort(g_cmd_names, len);
}

void			create_arr_names(void)
{
	extern	int		g_prog_names_count;
	extern	t_hash	**g_table;
	int				i;
	int				j;

	i = 0;
	j = 0;
//	printf("%d\n", g_prog_names_count);
	if (g_prog_names_count)
	{
		if ((g_cmd_names = (char **)ft_memalloc((sizeof(char *) *
						(g_prog_names_count + 1)))) == NULL)
			die();
		while (i < HASH_LEN)
		{
			if (*(g_table + i))
				add_names(*(g_table + i), g_cmd_names, &j);
			++i;
		}
//		check_god(g_cmd_names);
		sort_arr_names(g_prog_names_count);
//		check_god(g_cmd_names);
	}
}
