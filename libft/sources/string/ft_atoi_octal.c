/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_octal.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jterry <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/25 18:33:16 by jterry            #+#    #+#             */
/*   Updated: 2019/08/25 18:33:41 by jterry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isdigit_octal(char c)
{
	if (c >= '0' && c <= '7')
		return (1);
	return (0);
}

t_uchar		ft_atoi_octal(char *str, int *count)
{
	t_uchar	result;
	int		i;

	result = 0;
	i = 0;
	while (ft_isdigit_octal(str[i]))
	{
		result = result * 8 + (str[i] - '0');
		i++;
	}
	*count = i;
	return (result);
}
