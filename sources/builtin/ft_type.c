/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggwin-go <ggwin-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/03 14:22:58 by ggwin-go          #+#    #+#             */
/*   Updated: 2019/08/07 14:20:17 by ggwin-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

static int	res_for_cmd_not_found(const char *cmd)
{
	ft_putstr(PROJECT_NAME ": type: ");
	ft_putstr(cmd);
	ft_putendl(": not found");
	return (1);
}

int			ft_type(const char **av)
{
	char	*path;
	int		res;

	res = 0;
	if (av)
		while (*av)
		{
			if (check_builtin((char *)*av))
			{
				ft_putstr(*av);
				ft_putendl(" is a shell builtin");
				res = 1;
			}
			else if ((path = get_bin((char *)*av)))
			{
				ft_putstr(*av);
				ft_putstr(" is ");
				ft_putendl(path);
				res = 1;
			}
			else
				res = res_for_cmd_not_found(*av);
			++av;
		}
	return (res);
}
