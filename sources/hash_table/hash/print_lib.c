/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_lib.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wtalea <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/25 19:21:39 by wtalea            #+#    #+#             */
/*   Updated: 2019/08/26 18:25:55 by wtalea           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hash.h"

static	void	print_more_space(int int_len, int count)
{
	int_len -= 4;
	count -= 7;
	while (int_len < count)
		write(1, " ", 1);
}

void			print_number(int count, char num[13], char *str, int num_len)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (num_len < 4)
	{
		i = ((4 - num_len) < 0) ? 0 : (4 - num_len);
		while (i--)
			write(1, " ", 1);
	}
	write(1, (char *)num, ft_strlen((char *)num));
	num_len = ((num_len - 4) < 0) ? 0 : num_len - 4;
	if (num_len < 4)
	{
		i = ((4 - num_len) < 0) ? 0 : (4 - num_len);
		while (i--)
			write(1, " ", 1);
	}
	if (count >= 8)
		print_more_space(num_len, count);
	write(1, str, ft_strlen(str));
	write(1, "\n", 1);
}
