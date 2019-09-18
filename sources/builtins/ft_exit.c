/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jterry <jterry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 17:41:34 by ggwin-go          #+#    #+#             */
/*   Updated: 2019/09/16 17:10:04 by jterry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

static void	check_arg_count(const char **av)
{
	int	ac;

	ac = 0;
	while (*(av++))
	{
		++ac;
		if (ac > 1)
		{
			ft_putstr_fd(g_project_name, 2);
			ft_putendl_fd(": exit: too many arguments", 2);
			exit(1);
		}
	}
}

static void	check_arg_format(const char *av)
{
	const char	*tmp;

	tmp = av;
	while (*tmp)
	{
		if (!ft_isdigit(*(tmp++)))
		{
			ft_putstr_fd(g_project_name, 2);
			ft_putstr_fd(": exit: ", 2);
			ft_putstr_fd(av, 2);
			ft_putendl_fd(": numeric argument required", 2);
			exit(255);
		}
	}
}

int			ft_exit(const char **av)
{
	char		res;

	if (av && *av)
	{
		check_arg_count(av);
		check_arg_format(*av);
		res = (char)ft_atoi(*av);
		exit(res);
	}
	exit(g_res_exec);
}
