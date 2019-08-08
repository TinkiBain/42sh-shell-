/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggwin-go <ggwin-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 17:41:34 by ggwin-go          #+#    #+#             */
/*   Updated: 2019/08/07 17:35:02 by ggwin-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "defs.h"

static void	check_arg_count(const char **av)
{
	int	ac;

	ac = 0;
	while (*(av++))
	{
		++ac;
		if (ac > 1)
		{
			ft_putendl_fd(PROJECT_NAME ": exit: too many arguments", 2);
			exit(1);
		}
	}
}

int			ft_exit(const char **av)
{
	const char	*tmp;
	char		res;

	if (av && *av)
	{
		check_arg_count(av);
		tmp = *av;
		while (*tmp)
		{
			if (!ft_isdigit(*(tmp++)))
			{
				ft_putstr_fd(PROJECT_NAME ": exit: ", 2);
				ft_putstr_fd(*av, 2);
				ft_putendl_fd(": numeric argument required", 2);
				exit(255);
			}
		}
		res = (char)ft_atoi(*av);
		exit(res);
	}
	exit(0);
}
