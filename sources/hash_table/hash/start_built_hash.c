/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_built_hash.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wtalea <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/24 16:47:06 by wtalea            #+#    #+#             */
/*   Updated: 2019/08/26 18:05:52 by wtalea           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hash.h"

#define FLAG_R 0x1
#define FLAG_D 0x2
#define FLAG_L 0x4
#define FLAG_P 0x8
#define FLAG_T 0x10

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
		while (*(argv))
		{
			find_and_del_hash(*argv);
			++argv;
		}
}

static void		hash_work_flags(int flags, char **argv)
{
	if (flags & FLAG_R)
		del_all_hash();
	if (*argv)
		hash_erase(argv);
}

int				hash_start_work(int flags, char **argv)
{
	if (flags)
		hash_work_flags(flags, argv);
	else if (*argv)
		hash_erase(argv);
	else
		hash_print();
	return (0);
}
