/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelisan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 16:25:05 by gmelisan          #+#    #+#             */
/*   Updated: 2019/10/23 22:37:04 by gmelisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	t_uchar	ucs1;
	t_uchar	ucs2;

	if (n > ft_strlen(s1))
		return (ft_strcmp(s1, s2));
	else
	{
		i = 0;
		while (i < n)
		{
			ucs1 = *((t_uchar *)s1 + i);
			ucs2 = *((t_uchar *)s2 + i);
			if (ucs1 != ucs2)
				return (ucs1 - ucs2);
			i++;
		}
		return (0);
	}
}
