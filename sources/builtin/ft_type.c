/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggwin-go <ggwin-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/03 14:22:58 by ggwin-go          #+#    #+#             */
/*   Updated: 2019/08/03 14:37:23 by ggwin-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

static int	check_builtin(char *cmd)
{
	if (ft_strequ("cd", cmd) || ft_strequ("echo", cmd) ||
			ft_strequ("env", cmd) || ft_strequ("setenv", cmd) ||
			ft_strequ("unsetenv", cmd) || ft_strequ("hash", cmd) ||
			ft_strequ("type", cmd))
		return (1);
	return (0);
}

void		ft_type(char **av)
{
	if (av)
		while (*av)
		{
			if (check_builtin(*av))
			{
				ft_putstr(*av);
				ft_putendl(" is a shell builtin");
			}
			else if (get_bin(*av, g_table))
			{
				ft_putstr(*av);
				ft_putendl(" is a shell builtin");
			}
			else
			{
				ft_putstr(PROJECT_NAME);
				ft_putstr(": type: ");
				ft_putstr(*av);
				ft_putendl(": not found");
			}
			++av;
		}
}
