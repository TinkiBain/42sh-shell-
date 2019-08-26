/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_and_del.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wtalea <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/26 17:31:49 by wtalea            #+#    #+#             */
/*   Updated: 2019/08/26 17:36:59 by wtalea           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hash.h"

void	find_and_del_hash(char *name)
{
	t_hash		*table;

	table = NULL;
	if ((table = get_hash_struct(name)) == NULL)
		hash_not_found(name);
	else
	{
		table->hash_on = 1;
		table->hash_count = 0;
	}
}
