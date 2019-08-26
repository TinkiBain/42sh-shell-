/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash_print_use.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wtalea <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/24 17:13:49 by wtalea            #+#    #+#             */
/*   Updated: 2019/08/26 17:22:40 by wtalea           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hash.h"

static	void	print_hits_command(int count)
{
	write(1, "hist", 4);
	write(1, "    ", 4);
	count -= 7;
	count = (count < 0) ? 0 : count;
	while (count--)
		write(1, " ", 1);
	write(1, "command\n", 8);
}

void			hash_print_new(int count, t_hash *table[count], int count_len)
{
	int		i;
	char	num[13];

	i = 0;
	print_hits_command(count_len);
	while (i < (count))
	{
		ft_itoa_nm((*(table + i))->hash_count, num);
		print_number(count_len, num, (*(table + i))->path,
				ft_intlen((*(table + i))->hash_count));
		++i;
	}
}
