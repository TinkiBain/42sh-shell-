/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jterry <jterry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 17:41:34 by ggwin-go          #+#    #+#             */
/*   Updated: 2019/10/09 17:24:16 by gmelisan         ###   ########.fr       */
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
			print_error_exit("exit", "too many arguments", 1);
	}
}

static void	check_arg_format(const char *av)
{
	const char	*tmp;

	tmp = av;
	while (*tmp)
	{
		if (!ft_isdigit(*(tmp++)))
			print_error_exit("exit", "numeric argument required", 255);
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
		shell_clear();
		exit(res);
	}
	shell_clear();
	exit(g_res_exec);
}
