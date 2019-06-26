/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_lli.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggwin-go <ggwin-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/05 16:01:22 by ggwin-go          #+#    #+#             */
/*   Updated: 2019/02/06 13:17:38 by ggwin-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putnbr_lli(long long int n)
{
	unsigned long long int	num;
	char					c;

	if (n < 0)
	{
		write(1, "-", 1);
		num = (unsigned long long int)(-n);
	}
	else
		num = (unsigned long long int)n;
	if (num >= 10)
		ft_putnbr_lli(num / 10);
	c = (num % 10) + '0';
	write(1, &c, 1);
}
