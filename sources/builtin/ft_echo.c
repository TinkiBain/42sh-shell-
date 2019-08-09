/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggwin-go <ggwin-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/27 12:31:45 by ggwin-go          #+#    #+#             */
/*   Updated: 2019/08/08 20:26:27 by ggwin-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

int		ft_echo(const char **av)
{
	int		flag;

	flag = 1;
	if (av && *av)
	{
		if (ft_strequ("-n", *av))
		{
			flag = 0;
			++av;
		}
		while (*av)
		{
			ft_putstr(*av);
			if (*(++av))
				write(1, " ", 1);
		}
	}
	if (flag)
		write(1, "\n", 1);
	return (0);
}
