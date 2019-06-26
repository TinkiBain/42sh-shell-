/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_llitoa.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwisoky <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/11 04:05:55 by dwisoky           #+#    #+#             */
/*   Updated: 2019/05/13 22:12:22 by dwisoky          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_llitoa(unsigned long long int nb)
{
	int		i;
	int		j;
	char	tmp[64];
	char	*str;

	j = 0;
	while (nb)
	{
		tmp[j] = nb % 10 + '0';
		nb /= 10;
		++j;
	}
	str = (char*)ft_xmalloc(sizeof(char) * (j + 1));
	i = 0;
	while (j > 0)
	{
		str[i] = tmp[j - 1];
		i++;
		j--;
	}
	return (str);
}
