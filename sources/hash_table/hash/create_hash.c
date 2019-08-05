/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_hash.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wtalea <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/01 17:37:11 by wtalea            #+#    #+#             */
/*   Updated: 2019/08/02 16:19:39 by wtalea           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hash.h"

static void			part2_generate(unsigned int *hash, long rem, unsigned int i,
						const unsigned char *data)
{
	unsigned char	trail;

	while (rem >= 0)
	{
		trail = *(unsigned char*)data;
		trail += i++;
		*hash ^= trail;
		*hash *= 171717;
		data++;
		rem--;
	}
}

unsigned int		generate_hash(char *str, unsigned int len)
{
	unsigned int		hash;
	unsigned int		i;
	unsigned int		k;
	long				rem;
	const unsigned char *data;

	hash = len;
	i = 0;
	rem = len;
	data = (const unsigned char *)str;
	while (rem >= 4)
	{
		k = *(unsigned int*)data;
		k += i++;
		hash ^= k;
		hash *= 171717;
		data += 4;
		rem -= 4;
	}
	part2_generate(&hash, rem, i, data);
	return (hash);
}
