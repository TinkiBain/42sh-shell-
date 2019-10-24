/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_arr_names.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wtalea <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/19 15:34:35 by wtalea            #+#    #+#             */
/*   Updated: 2019/10/13 12:23:06 by wtalea           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hash.h"

#define INTS_LEN 4
#define I ints[0]
#define J ints[1]
#define LEN_ALIAS ints[2]
#define LEN_FUNC ints[3]

char			**g_cmd_names;
extern t_alias	*g_alias;
extern t_dict	*g_func_defs;

static	int		find_name(char *name, char **cmd)
{
	while (cmd)
	{
		if (strcmp(name, *cmd))
			return (1);
		++cmd;
	}
	return (0);
}

static	void	add_names(t_hash *table, char **names, int *j)
{
	while (table)
	{
		*(names + *j) = table->name;
		++(*j);
		table = table->next;
	}
}

static	void	add_names_alias(t_alias *alias, int *j)
{
	while (alias)
	{
		if (find_name(alias->head, g_cmd_names))
		{
			*(g_cmd_names + *j) = alias->head;
			++(*j);
		}
		alias = alias->next;
	}
}

static	void	add_names_func(t_dict *func, int *j)
{
	while (func)
	{
		if (find_name(func->key, g_cmd_names))
		{
			*(g_cmd_names + *j) = func->key;
			++(*j);
		}
		func = func->next;
	}
}

void			create_arr_names(void)
{
	extern	int		g_prog_names_count;
	extern	t_hash	**g_table;
	int				ints[INTS_LEN];

	ft_bzero(ints, (sizeof(int) * INTS_LEN));
	LEN_ALIAS = alias_size_list(g_alias);
	LEN_FUNC = func_size_list(g_func_defs);
	if (g_prog_names_count || LEN_ALIAS || LEN_FUNC)
	{
		g_cmd_names = (char **)ft_xmemalloc((sizeof(char *) *
					(g_prog_names_count + LEN_ALIAS + LEN_FUNC + 1)));
		if (g_prog_names_count)
			while (I < HASH_LEN)
			{
				if (*(g_table + I))
					add_names(*(g_table + I), g_cmd_names, &J);
				++I;
			}
		if (LEN_ALIAS)
			add_names_alias(g_alias, &J);
		if (LEN_FUNC)
			add_names_func(g_func_defs, &J);
		ft_arr_str_qsort(g_cmd_names,
				g_prog_names_count + LEN_ALIAS + LEN_FUNC);
	}
}
