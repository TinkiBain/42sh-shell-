/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggwin-go <ggwin-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/25 19:35:49 by ggwin-go          #+#    #+#             */
/*   Updated: 2018/12/29 19:00:01 by ggwin-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>

char	*ft_itoa(int n)
{
	unsigned int	num;
	int				size;
	char			sign;
	char			*str;

	sign = (n < 0) ? 1 : 0;
	size = (n < 0) ? 2 : 1;
	num = (unsigned int)((n < 0) ? ((-1) * n) : n);
	while (size++ && (n / 10) != 0)
		n /= 10;
	if (!(str = (char *)malloc(sizeof(char) * (size))))
		return (NULL);
	str[size-- - 1] = '\0';
	while (size > 0)
	{
		str[--size] = (num % 10) + '0';
		num /= 10;
	}
	if (sign == 1)
		str[0] = '-';
	return (str);
}
