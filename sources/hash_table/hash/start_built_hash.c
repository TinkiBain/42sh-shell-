/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_built_hash.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wtalea <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/24 16:47:06 by wtalea            #+#    #+#             */
/*   Updated: 2019/08/24 16:54:15 by wtalea           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hash.h"

static void	hash_work_flags(int flags, char **argv)
{
	return ;
}

int		hash_start_work(int flags, char **argv)
{
	if (flags)
		hash_work_flags(flags, argv);
	if (*argv)
		hash_erase(argv);
	else
		hash_print();
}
