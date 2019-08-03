/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsetenv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggwin-go <ggwin-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/17 22:04:36 by ggwin-go          #+#    #+#             */
/*   Updated: 2019/08/03 20:10:13 by ggwin-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

int		ft_unsetenv(char **av)
{
	char		**tmp;
	size_t		len;
	extern char	**environ;

	if (!environ)
		return (0);
	while (*av)
	{
		len = ft_strlen(*av);
		tmp = environ;
		while (*tmp && !(ft_strnequ(*av, *tmp, len) && (*tmp)[len] == '='))
			++tmp;
		if (*tmp)
		{
			// *environ = (char **)ft_vector_remove((void **)*environ, (void *)*tmp);
			if (len == 4 && ft_strnequ(*av, "PATH", 4))
			{
				ft_free_double_ptr_arr((void ***)&g_table);
				// free_binary_tree();
			}
		}
		++av;
	}
	return (1);
}
