/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsetenv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggwin-go <ggwin-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/17 22:04:36 by ggwin-go          #+#    #+#             */
/*   Updated: 2019/08/03 14:17:13 by ggwin-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

int		ft_unsetenv(char **av, char ***env, t_list **head)
{
	char	**tmp;
	size_t	len;

	if (!env)
		return (0);
	while (*av)
	{
		len = ft_strlen(*av);
		tmp = *env;
		while (*tmp && !(ft_strnequ(*av, *tmp, len) && (*tmp)[len] == '='))
			++tmp;
		if (*tmp)
		{
			*env = (char **)ft_vector_remove((void **)*env, (void *)*tmp);
			if (len == 4 && ft_strnequ(*av, "PATH", 4))
			{
				ft_free_double_ptr_arr(&g_table);
				ft_lstdel(head);
			}
		}
		++av;
	}
	return (1);
}
