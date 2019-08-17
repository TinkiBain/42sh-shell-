/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsetenv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggwin-go <ggwin-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/17 22:04:36 by ggwin-go          #+#    #+#             */
/*   Updated: 2019/08/17 15:34:17 by ggwin-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"
#include "hash.h"

int		ft_unsetenv(const char **av)
{
	extern char	**environ;
	size_t		len;

	if (!environ)
		return (1);
	while (*av)
	{
		if (!check_readonly_var(*av))
		{
			remove_var(*av, &environ);
			len = ft_strlen(*av);
			if (len == 4 && ft_strnequ(*av, "PATH", 4))
				del_hash();
		}
		++av;
	}
	return (1);
}
