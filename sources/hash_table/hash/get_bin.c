/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_bin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggwin-go <ggwin-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/02 15:19:39 by wtalea            #+#    #+#             */
/*   Updated: 2019/08/24 16:59:26 by wtalea           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hash.h"

static	char	*find_path(char *name, unsigned int key, t_hash *table)
{
	while (table)
	{
		if (table->hash == key)
			if (ft_strequ(name, table->name))
				return (table->path);
		table = table->next;
	}
	return (NULL);
}

static	t_hash	*find_table(char *name, unsigned int key, t_hash *table)
{
	while (table)
	{
		if (table->hash == key)
			if (ft_strequ(name, table->name))
				return (table);
		table = table->next;
	}
	return (NULL);
}

t_hash			*get_hash_struct(char *name)
{
	unsigned int	key;
	t_hash			*table;
	extern	t_hash	**g_table;

	key = 0;
	table = NULL;
	key = generate_hash(name, ft_strlen(name));
	if (!g_table)
		return (NULL);
	if (*(g_table + (key % HASH_LEN)))
		table = find_table(name, key, *(g_table + (key % HASH_LEN)));
	return (table);
}

char			*get_bin(char *name)
{
	unsigned int	key;
	char			*path;
	extern	t_hash	**g_table;

	key = 0;
	path = NULL;
	key = generate_hash(name, ft_strlen(name));
	if (!g_table)
		return (NULL);
	if (*(g_table + (key % HASH_LEN)))
		path = find_path(name, key, *(g_table + (key % HASH_LEN)));
	return (path);
}
