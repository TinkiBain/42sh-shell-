/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup_len_len.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggwin-go <ggwin-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 19:13:11 by ggwin-go          #+#    #+#             */
/*   Updated: 2019/02/20 16:55:34 by ggwin-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_bits(char ch)
{
	int	i;

	i = 0;
	if (ch & 0x40)
		i++;
	if (ch & 0x20)
		i++;
	if (ch & 0x10)
		i++;
	return (i);
}

char		*ft_strdup_len_len(const char *src, size_t *len,
												size_t *printable_len)
{
	char	*s;
	char	*tmp;
	int		count;

	*len = 0;
	*printable_len = 0;
	tmp = (char *)src;
	while (*tmp)
	{
		if (*tmp & 0x80)
		{
			count = count_bits(*tmp);
			*len += count;
			tmp += count;
		}
		(*printable_len)++;
		(*len)++;
		tmp++;
	}
	s = (char *)malloc(sizeof(char) * (*len + 1));
	if (s == NULL)
		return (NULL);
	return (ft_memmove(s, src, (*len + 1)));
}
