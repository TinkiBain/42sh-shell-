/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwisoky <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 13:15:19 by dwisoky           #+#    #+#             */
/*   Updated: 2019/04/25 17:56:19 by dwisoky          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	int		i;
	int		len;
	char	*str;

	i = 0;
	len = 0;
	if (!src)
		return (NULL);
	while (src[len] != '\0')
		len++;
	str = (char*)ft_xmalloc(sizeof(char) * (len + 1));
	while (i <= len)
	{
		str[i] = src[i];
		i++;
	}
	return (str);
}
