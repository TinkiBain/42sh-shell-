/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggwin-go <ggwin-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/17 22:04:36 by ggwin-go          #+#    #+#             */
/*   Updated: 2019/08/17 23:38:36 by ggwin-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"
#include "hash.h"

int		ft_unset(const char **av)
{
	extern char	**g_var;
	extern char	**environ;
	size_t		len;

	if (!g_var)
		return (1);
	while (*av)
	{
		if (!check_readonly_var(*av))
		{
			remove_var(*av, &g_var);
			if (getenv(*av))
				remove_var(*av, &environ);
			len = ft_strlen(*av);
			if (len == 4 && ft_strnequ(*av, "PATH", 4))
				del_hash();
		}
		++av;
	}
	return (1);
}
