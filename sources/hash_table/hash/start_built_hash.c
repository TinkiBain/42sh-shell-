/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_built_hash.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wtalea <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/24 16:47:06 by wtalea            #+#    #+#             */
/*   Updated: 2019/08/26 15:16:44 by wtalea           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hash.h"

void			hash_add_count(char *name)
{
	t_hash		*table;

	table = NULL;
	if ((table = get_hash_struct(name)))
	{
		table->hash_on = 1;
		++table->hash_count;
	}
}

void			hash_erase(char **argv)
{
	if (argv)
		;
}

static void		hash_work_flags(int flags, char **argv)
{
	if (flags && argv)
		return ;
}

int				hash_start_work(int flags, char **argv)
{
	if (flags)
		hash_work_flags(flags, argv);
	if (*argv)
		hash_erase(argv);
	else
		hash_print();
	return (0);
}
