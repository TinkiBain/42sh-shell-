/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggwin-go <ggwin-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/17 22:04:36 by ggwin-go          #+#    #+#             */
/*   Updated: 2019/08/06 15:30:57 by wtalea           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"
#include "hash.h"

static void	replace_var(char *av, char **tmp, char ***env)
{
	char	*var;

	var = ft_strdup(av);
	if (tmp && *tmp)
	{
		free(*tmp);
		*tmp = var;
	}
	(void)env;
	// else
	// 	*env = (char **)ft_vector_add((void **)*env, (void *)var);
}

int			ft_setenv(char **av)
{
	char			*p;
	char			**tmp;
	extern	char	**environ;

	if (!environ)
		return (0);
	while (*av)
	{
		tmp = environ;
		p = ft_strchr(*av, '=');
		if (!p && ++av)
			continue ;
		while (*tmp && !ft_strnequ(*av, *tmp, p - *av + 1))
			++tmp;
		replace_var(*av, tmp, &environ);
		if (ft_strnequ(*av, "PATH=", 5))
		{
			fill_hash_table();
		}
		++av;
	}
	return (1);
}
