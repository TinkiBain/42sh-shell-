/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_force.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wtalea <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/19 14:43:31 by wtalea            #+#    #+#             */
/*   Updated: 2019/08/19 15:18:57 by wtalea           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hash.h"

static	void	add_force_hash(char *name, t_hash *table, char *path,
		unsigned int key)
{
	while (table->next)
	{
		if (table->hash == key && ft_strequ(name, table->name))
		{
			table->path ? free(table->path) : 1;
			table->path = path ? ft_xstrdup(path) : NULL;
		}
		table = table->next;
	}
	if (table->hash == key && ft_strequ(name, table->name))
	{
		table->path ? free(table->path) : 1;
		table->path = path ? ft_xstrdup(path) : NULL;
	}
	table->next = create_hash(name, path, key);
}

static	void			add_force_build(char *name, char *path)
{
	extern		t_hash		**g_table;
	unsigned	int			key;

	key = 0;
	if (name)
	{
		key = generate_hash(name, ft_strlen(name));
		if (!*((g_table) + key % HASH_LEN))
			*((g_table) + key % HASH_LEN) = create_hash(name, path, key);
		else
			add_force_hash(name, *((g_table) + key % HASH_LEN), path, key);
	}
}

void					add_force_builds(void)
{
	add_force_build("alias", NULL);
	add_force_build("bg", NULL);
	add_force_build("cd", NULL);
	add_force_build("echo", NULL);
	add_force_build("env", NULL);
	add_force_build("exit", NULL);
	add_force_build("fc", NULL);
	add_force_build("fg", NULL);
	add_force_build("hash", NULL);
	add_force_build("jobs", NULL);
	add_force_build("set", NULL);
	add_force_build("setenv", NULL);
	add_force_build("time", NULL);
	add_force_build("type", NULL);
	add_force_build("unalias", NULL);
	add_force_build("unset", NULL);
	add_force_build("unsetenv", NULL);
}
