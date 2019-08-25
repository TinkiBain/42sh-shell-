/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_vec_prog.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggwin-go <ggwin-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 20:21:51 by wtalea            #+#    #+#             */
/*   Updated: 2019/08/25 14:04:24 by ggwin-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hash.h"
#include "utils.h"

static int		match(char *query, int len_query, char *name, int len_name)
{
	int i;

	i = 0;
	if (len_query > len_name)
		return (0);
	while (i < len_query)
	{
		if (name[i] != query[i])
			return (0);
		i++;
	}
	return (1);
}

static void		add_vector(t_string query, t_vector *vector, t_hash *table)
{
	t_string	s;

	while (table)
	{
		if (match(query.s, query.len, table->name, ft_strlen(table->name)))
		{
			s = str_copy(table->name);
			str_addback(&s, " ", 1);
			vec_addback(vector, &s);
		}
		table = table->next;
	}
}

static	void	fill_vector(t_string query, t_vector *vector, t_hash **table)
{
	int			i;
	t_string	s;

	i = 0;
	while (i < HASH_LEN)
		add_vector(query, vector, table[i++]);
	if (match(query.s, query.len, "./", 2))
	{
		s = str_copy("./");
		vec_addback(vector, &s);
	}
}

t_vector		get_vec_prog(t_string query)
{
	t_vector		vec;
	extern	t_hash	**g_table;

	vec = vec_create(0, sizeof(t_string));
	fill_vector(query, &vec, g_table);
	ft_qsort(vec.v, vec.len, vec.size, cmp_pstring);
	return (vec);
}
