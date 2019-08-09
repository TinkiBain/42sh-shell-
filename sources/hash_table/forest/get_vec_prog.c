/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_vec_prog.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wtalea <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 20:21:51 by wtalea            #+#    #+#             */
/*   Updated: 2019/08/09 15:46:46 by wtalea           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vector.h"
#include "hash.h"
#include "libft.h"

static	void	add_vector(char *str, t_vector *vector, t_hash *table)
{
	size_t		len;

	len = 0;
	if (vector)
		;
	len = ft_strlen(str);
	if (table)
	{
		while (table)
		{
			if (len <= ft_strlen(table->name))
				if (!ft_memcmp(str, table->name, ft_strlen(str)))
					vec_addback(vector, &table->name);
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

t_vector		*get_vec_prog(char *str)
{
	t_vector		*vector;
	extern	t_hash	**g_table;

	vector = NULL;
	vector = (t_vector *)ft_xmalloc(sizeof(t_vector));
	*vector = vec_create(0, sizeof(char *));
	fill_vector(str, vector, g_table);
	return (vector);
}
