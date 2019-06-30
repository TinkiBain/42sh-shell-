/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggwin-go <ggwin-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 16:32:23 by ggwin-go          #+#    #+#             */
/*   Updated: 2018/12/01 01:45:45 by ggwin-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar_fd(char c, int fd)
{
	unsigned char	ch;
	char			a;
	char			b;

	ch = (unsigned char)c;
	if (ch < 128)
		write(fd, &ch, 1);
	else
	{
		a = 192 + ch / 64;
		b = 128 + ch % 64;
		write(fd, &a, 1);
		write(fd, &b, 1);
	}
}
