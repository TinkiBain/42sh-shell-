/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggwin-go <ggwin-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 15:47:16 by ggwin-go          #+#    #+#             */
/*   Updated: 2019/10/07 14:55:14 by ggwin-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putnbr(int n)
{
	unsigned int	num;
	char			c;

	if (n < 0)
	{
		write(1, "-", 1);
		num = (unsigned int)(-n);
	}
	else
		num = (unsigned int)n;
	if (num >= 10)
		ft_putnbr(num / 10);
	c = (num % 10) + '0';
	write(1, &c, 1);
}
