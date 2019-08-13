/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_vec_prog.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wtalea <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 20:21:51 by wtalea            #+#    #+#             */
/*   Updated: 2019/08/13 08:04:29 by gmelisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_string.h"
#include "ft_vector.h"
#include "ft_qsort.h"
#include "hash.h"

static int		cmp(const void *a, const void *b)
{
	return (ft_strcmp(((t_string *)a)->s,
					  ((t_string *)b)->s));
}

static	void	add_vector(char *s, t_vector *vector, t_hash *table)
{
	size_t		len;
	t_string	str;

	len = 0;
	len = ft_strlen(s);
	if (table)
	{
		while (table)
		{
			if (len <= ft_strlen(table->name))
				if (!ft_memcmp(s, table->name, ft_strlen(s)))
				{
					str.s = table->name;
					str_fixlen(&str);
					vec_addback(vector, &str);
				}
			table = table->next;
		}
	}
}

static	void	fill_vector(char *str, t_vector *vector, t_hash **table)
{
	int		i;

	i = 0;
	while (i < HASH_LEN)
	{
		add_vector(str, vector, *(table + i));
		++i;
	}
}

t_vector		get_vec_prog(char *str)
{
	t_vector		vec;
	extern	t_hash	**g_table;

	vec = vec_create(0, sizeof(t_string));
	fill_vector(str, &vec, g_table);
	ft_qsort(vec.v, vec.len, vec.size, cmp);
	return (vec);
}
