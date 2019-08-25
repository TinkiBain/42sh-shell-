/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_lib.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wtalea <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/25 19:21:39 by wtalea            #+#    #+#             */
/*   Updated: 2019/08/25 20:27:55 by wtalea           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hash.h"

void	print_number(int count, char num[13], char *str)
{
	int		i;

	i = 0;
	if (count < 4)
	{
		i = count;
		while (i--)
			write(1, " ", 1);
	}
	write(1, num, ft_strlen(num));
	if (count < 8)
	{
		i = count;
		while (count-- > 4)
			write(1, " ", 1);
	}
	write(1, str, ft_strlen(str));
	write(1, "\n", 1);
}
