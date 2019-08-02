/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_bin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggwin-go <ggwin-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/01 17:40:24 by wtalea            #+#    #+#             */
/*   Updated: 2019/08/02 20:14:29 by ggwin-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_env.h"
#include "hash.h"

t_hash			*create_hash(char *name, char *path, unsigned int key)
{
	t_hash		*temp;

	temp = NULL;
	if ((temp = (t_hash *)malloc(sizeof(t_hash))) == NULL)
		die_log("malloc in fill_hash");
	if ((temp->name = ft_strdup(name)) == NULL)
		die_log("malloc in fill_hash");
	if ((temp->path = ft_strdup(path)) == NULL)
		die_log("malloc in fill_hash");
	temp->hash = key;
	temp->next = NULL;
	return (temp);
}

static	void	add_hash(char *name, t_hash *table, char *path,
		unsigned int key)
{
	while (table->next)
	{
		if (table->hash == key && ft_strequ(name, table->name))
			return ;
		table = table->next;
	}
	if (table->hash == key && ft_strequ(name, table->name))
		return ;
	table->next = create_hash(name, path, key);
}

static	void	fill_hash(char *name, t_hash ***table, char *path)
{
	unsigned int	key;

	key = 0;
	if (path && name && !(*name == '.' && *(name + 1) == '\0') && !(*name == '.'
				&& *(name + 1) == '.' && *(name + 2) == '\0'))
	{
		key = generate_hash(name, ft_strlen(name));
		if (!*((*table) + key % HASH_LEN))
			*((*table) + key % HASH_LEN) = create_hash(name, path, key);
		else
			add_hash(name, *((*table) + key % HASH_LEN), path, key);
	}
	if (path)
		free(path);
}

static	void	split_hash(char *str, t_hash ***table)
{
	DIR				*dir;
	struct dirent	*diren;

	if (!access(str, X_OK))
	{
		if ((dir = opendir(str)) == NULL)
			return ;
		diren = readdir(dir);
		if (diren)
			fill_hash(diren->d_name, table, paste_path(str, diren->d_name));
		while ((diren = readdir(dir)))
			fill_hash(diren->d_name, table, paste_path(str, diren->d_name));
		closedir(dir);
	}
}

void			create_bin(char *str, t_hash ***table)
{
	int		i;
	char	**cp;

	cp = NULL;
	i = 0;
	if ((cp = ft_strsplit(str, ':')) == NULL)
		die_log("malloc in get_bin");
	while (*(cp + i))
		split_hash(*(cp + i++), table);
	ft_free_char_arr((void ***)&cp);
}
