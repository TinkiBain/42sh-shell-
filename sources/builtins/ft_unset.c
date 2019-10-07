/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggwin-go <ggwin-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/17 22:04:36 by ggwin-go          #+#    #+#             */
/*   Updated: 2019/10/07 15:05:19 by ggwin-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"
#include "hash.h"

int		ft_unset(const char **av)
{
	extern char	**g_var;
	extern char	**g_func_defs;
	extern char	**environ;
	size_t		len;
	int			flag;

	if (!g_var)
		return (1);
	flag = (ft_strequ(*av, "-f")) ? 1 : 0;
	while (*av)
	{
		len = ft_strlen(*av);
		if (flag)
			remove_var(*av, &g_func_defs);
		else if (!check_readonly_var(*av, len))
		{
			remove_var(*av, &g_var);
			remove_var(*av, &environ);
			if (len == 4 && ft_strnequ(*av, "PATH", 4))
				fill_hash_table();
		}
		++av;
	}
	return (1);
}
