/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_flags.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wtalea <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/29 17:08:40 by wtalea            #+#    #+#             */
/*   Updated: 2019/08/29 17:10:23 by wtalea           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hash.h"

char		**get_flags(char *name)
{
	t_hash		*table;

	table = NULL;
	if ((table = get_hash_struct(name)))
		return (table->flags_args);
	return (NULL);
}
