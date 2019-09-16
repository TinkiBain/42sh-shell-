/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_bin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wtalea <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/19 15:18:14 by wtalea            #+#    #+#             */
/*   Updated: 2019/09/16 12:53:09 by gmelisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hash.h"
#include "xfuncs.h"

t_hash			**g_table;
int				g_prog_names_count;

t_hash			*create_hash(char *name, char *path, unsigned int key)
{
	t_hash		*temp;

	temp = (t_hash *)xmalloc(sizeof(t_hash));
	temp->name = ft_xstrdup(name);
	temp->path = path ? ft_xstrdup(path) : NULL;
	temp->hash = key;
	temp->hash_on = 0;
	temp->hash_count = 0;
	temp->next = NULL;
	temp->flags_args = NULL;
	++g_prog_names_count;
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

void			create_bin(char *str)
{
	int		i;
	char	**cp;

	if (!str)
		return ;
	cp = NULL;
	i = 0;
	cp = ft_xstrsplit(str, ':');
	while (*(cp + i))
		split_hash(*(cp + i++), &g_table);
	ft_free_double_ptr_arr((void ***)&cp);
}
