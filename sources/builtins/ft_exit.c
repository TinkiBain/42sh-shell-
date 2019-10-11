/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jterry <jterry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 17:41:34 by ggwin-go          #+#    #+#             */
/*   Updated: 2019/10/11 20:16:31 by gmelisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

static int	check_arg_count(const char **av)
{
	int	ac;

	ac = 0;
	while (*(av++))
	{
		++ac;
		if (ac > 1)
		{
			print_error_exit("exit", "too many arguments", 1);
			return (255);
		}
	}
	return (0);
}

static char	check_arg_format(const char *av)
{
	const char	*tmp;
	long		res;
	char		*str;

	tmp = av;
	str = NULL;
	if (*tmp == '-' || *tmp == '+')
		++tmp;
	res = 255;
	while (*tmp)
		if (!ft_isdigit(*(tmp++)))
		{
			print_error_vaarg("exit: %s: numeric argument required\n", av);
			return (res);
		}
	if (ft_strlen(av) > 20)
		print_error_vaarg("exit: %s: numeric argument required\n", av);
	else
		res = (char)ft_atoi(av);
	return ((char)res);
}

int			ft_exit(const char **av)
{
	char		res;

	res = (char)g_res_exec;
	if (av && *av)
	{
		if (!(res = check_arg_count(av)))
			res = check_arg_format(*av);
	}
	shell_clear();
	exit(res);
}
