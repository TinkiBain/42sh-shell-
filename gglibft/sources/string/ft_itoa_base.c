/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggwin-go <ggwin-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/31 09:56:42 by ggwin-go          #+#    #+#             */
/*   Updated: 2019/03/05 17:10:45 by ggwin-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count(unsigned long long int value, unsigned int base)
{
	unsigned int		i;

	i = 0;
	if (value == 0)
		return (1);
	while (value)
	{
		i++;
		value /= base;
	}
	return (i);
}

static void	ft_fill_str(unsigned long long int res, int base, char *str,
																int count)
{
	unsigned long long int	tmp;

	while (res)
	{
		if ((tmp = res % base) > 9)
			str[count] = tmp - 10 + 'A';
		else
			str[count] = tmp + '0';
		count--;
		res /= base;
	}
}

char		*ft_itoa_base(long long int value, int base)
{
	char					*str;
	unsigned long long int	res;
	int						count;
	int						sign;

	sign = (value < 0) ? 1 : 0;
	res = (sign == 1 && base == 10) ? -value : value;
	count = ft_count(res, base);
	count += (sign == 1 && base == 10) ? 1 : 0;
	str = (char *)malloc(sizeof(char) * (count + 1));
	str[count--] = '\0';
	if (value == 0)
		str[count] = '0';
	else
		ft_fill_str(res, base, str, count);
	if (sign == 1 && base == 10)
		str[0] = '-';
	return (str);
}
