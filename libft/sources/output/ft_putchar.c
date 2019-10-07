/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggwin-go <ggwin-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 20:43:09 by ggwin-go          #+#    #+#             */
/*   Updated: 2019/10/07 14:50:04 by ggwin-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	unsigned char	ch;
	char			a;
	char			b;

	ch = (unsigned char)c;
	if (ch < 128)
		write(1, &ch, 1);
	else
	{
		a = 192 + ch / 64;
		b = 128 + ch % 64;
		write(1, &a, 1);
		write(1, &b, 1);
	}
}
