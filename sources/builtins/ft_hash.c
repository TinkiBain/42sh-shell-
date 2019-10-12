/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hash.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggwin-go <ggwin-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/26 22:32:39 by ggwin-go          #+#    #+#             */
/*   Updated: 2019/10/12 14:00:29 by wtalea           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"
#include "hash.h"

#define FLAG_R 0x1
#define FLAG_D 0x2
#define FLAG_L 0x4
#define FLAG_P 0x8
#define FLAG_T 0x10
#define FLAGS "r"

static	int		hash_find_flags(int *flags, char c)
{
	if (c == 'r')
		*flags |= FLAG_R;
	else
	{
		hash_invalid_option(c);
		hash_usage();
		return (1);
	}
	return (0);
}

static	int		hash_flags_check(char **argv, int *i)
{
	int		j;
	int		flags;

	flags = 0;
	j = 0;
	while (*argv && **argv == '-')
	{
		if (*(*argv + 1) == '-')
		{
			++i;
			return (flags);
		}
		j = 1;
		while (*((*argv) + j))
		{
			if (hash_find_flags(&flags, *((*argv) + j)))
				return (-1);
			++j;
		}
		++(*i);
		++argv;
	}
	return (flags);
}

int				ft_hash(char **argv)
{
	int		flags;
	int		i;

	flags = 0;
	i = 0;
	flags = hash_flags_check(argv + 1, &i);
	if (flags == -1)
		return (1);
	return (hash_start_work(flags, (argv + 1 + i)));
}
