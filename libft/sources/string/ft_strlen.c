/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wtalea <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/23 16:28:23 by wtalea            #+#    #+#             */
/*   Updated: 2019/08/23 17:34:00 by wtalea           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	void	check_strlen(const char *str, unsigned long longs[5],
		const char *char_ptr, const unsigned long **longword_ptr)
{
	*longword_ptr = (unsigned long int *)char_ptr;
	longs[1] = 0x7efefeffL;
	longs[2] = 0x80808080L;
	longs[3] = 0x01010101L;
	if (sizeof(*longs) > 4)
	{
		longs[1] = ((0x7efefefeL << 16) << 16) | 0xfefefeffL;
		longs[2] = ((longs[2] << 16) << 16) | longs[2];
		longs[3] = ((longs[3] << 16) << 16) | longs[3];
	}
	if (sizeof(*longs) > 8)
		abort();
}

size_t			ft_strlen(const char *str)
{
	const	char						*char_ptr;
	const	char						*chars[2];
	const	unsigned	long			*longword_ptr;
	unsigned	long					longs[5];

	chars[0] = str;
	while (((unsigned long int)(chars[0]++) & (sizeof(*longs) - 1)) != 0)
		if (*chars[0] == '\0')
			return (chars[0] - str);
	check_strlen(str, longs, chars[0], &longword_ptr);
	while (1)
	{
		longs[4] = 0;
		*longs = *longword_ptr++;
		if (((*longs - longs[3]) & longs[2])
				!= 0)
		{
			chars[1] = (const char *)(longword_ptr - 1);
			while (longs[4] < 4 || ((sizeof(*longs) > 4) && longs[4] < 8))
				if (chars[1][longs[4]++] == 0)
					return (chars[1] - str + --longs[4]);
		}
	}
}
