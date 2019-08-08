/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggwin-go <ggwin-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/17 22:04:36 by ggwin-go          #+#    #+#             */
/*   Updated: 2019/08/08 21:59:48 by ggwin-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"
#include "hash.h"

static void	add_var(const char *av, char ***env)
{
	char	**new_env;
	char	**tmp;
	size_t	size;

	size = 0;
	tmp = *env;
	while (*(tmp + size))
		++size;
	new_env = (char **)ft_xmalloc(sizeof(char *) * (size + 2));
	ft_bzero(new_env, size + 1);
	tmp = new_env;
	while (size--)
		*(tmp++) = *((*env)++);
	*(tmp++) = ft_strdup(av);
	*tmp = NULL;
	*env = new_env;
}

static void	replace_var(const char *name, const char *var, char **env,
															size_t len)
{
	while (*env && !(ft_strnequ(name, *env, len) && *(*env + len) == '='))
		++env;
	if (*env)
	{
		// free(*env);
		*env = ft_strdup(var);
	}
}

int			add_env(const char **av, char ***env)
{
	char			*p;
	char			*name;

	if (!env)
		return (1);
	while (*av)
	{
		if ((p = ft_strchr(*av, '=')))
		{
			name = ft_strndup(*av, p - *av);
			if (!ft_getenv(name, *env))
				add_var(*av, env);
			else
				replace_var(name, *av, *env, p - *av);
			if (ft_strequ(name, "PATH"))
				fill_hash_table();
			free(name);
		}
		++av;
	}
	return (0);
}
