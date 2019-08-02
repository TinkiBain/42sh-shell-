/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_bin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wtalea <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/02 15:19:39 by wtalea            #+#    #+#             */
/*   Updated: 2019/08/02 15:41:24 by wtalea           ###   ########.fr       */
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

char			*get_bin(char *name, t_hash **table)
{
	unsigned int	key;
	char			*path;

	key = 0;
	path = NULL;
	key = generate_hash(name, ft_strlen(name));
	if (*(table + (key % HASH_LEN)))
		path = find_path(name, key, *(table + (key % HASH_LEN)));
	return (path);
}
