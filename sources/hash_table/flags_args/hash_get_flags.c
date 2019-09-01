/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash_get_flags.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggwin-go <ggwin-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/29 17:08:40 by wtalea            #+#    #+#             */
/*   Updated: 2019/09/01 20:18:10 by ggwin-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hash.h"

char		**hash_get_flags(char *name)
{
	t_hash		*table;

	table = NULL;
	if ((table = get_hash_struct(name)))
		return (table->flags_args);
	return (NULL);
}
