/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   null_hash.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wtalea <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/01 18:51:38 by wtalea            #+#    #+#             */
/*   Updated: 2019/08/01 20:10:26 by wtalea           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hash.h"

void	null_hash(t_hash *table[HASH_LEN])
{
	int		i;

	i = 0;
	while (i < HASH_LEN)
	{
		*((table) + i) = NULL;
		++i;
	}
}