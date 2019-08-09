/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsetenv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggwin-go <ggwin-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/17 22:04:36 by ggwin-go          #+#    #+#             */
/*   Updated: 2019/08/09 14:56:33 by ggwin-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"
#include "hash.h"

int		ft_unsetenv(const char **av)
{
	extern char	**environ;
	char		**tmp;
	size_t		len;

	if (!environ)
		return (1);
	while (*av)
	{
		len = ft_strlen(*av);
		tmp = environ;
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
			*(tmp + len - 1) = NULL;
			*(tmp + len) = NULL;
		}
		++av;
	}
	return (1);
}
