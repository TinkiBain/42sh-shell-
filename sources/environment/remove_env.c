/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_env.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggwin-go <ggwin-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/17 22:04:36 by ggwin-go          #+#    #+#             */
/*   Updated: 2019/08/08 22:01:32 by ggwin-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"
#include "hash.h"

int		remove_env(const char **av, char ***env)
{
	char		**tmp;
	size_t		len;

	if (!env)
		return (1);
	while (*av)
	{
		len = ft_strlen(*av);
		tmp = *env;
		while (*tmp && !(ft_strnequ(*av, *tmp, len) && *(*tmp + len) == '='))
			++tmp;
		if (*tmp)
		{
			free(*tmp);
			if (len == 4 && ft_strnequ(*av, "PATH", 4))
				del_hash();
			len = 0;
			while (*(tmp + ++len))
				*(tmp + len - 1) = *(tmp + len);
		}
		++av;
	}
	return (1);
}
