/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggwin-go <ggwin-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/17 22:04:36 by ggwin-go          #+#    #+#             */
/*   Updated: 2019/08/09 21:22:52 by ggwin-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"
#include "hash.h"

static void	add_var(const char *av, char ***env)
{
	char	**new_env;
	char	**tmp;
	char	**p;
	size_t	size;

	size = 0;
	p = *env;
	while (*(p++))
		++size;
	new_env = (char **)ft_xmalloc(sizeof(char *) * (size + 2));
	ft_bzero(new_env, sizeof(char *) * (size + 2));
	tmp = new_env;
	p = *env;
	while (*p)
		*(tmp++) = *(p++);
	*(tmp++) = ft_strdup(av);
	*tmp = NULL;
	free(*env);
	*env = new_env;
}

static void	replace_var(const char *name, const char *var, char **env,
															size_t len)
{
	while (*env && !(ft_strnequ(name, *env, len) && *(*env + len) == '='))
		++env;
	if (*env)
	{
		free(*env);
		*env = ft_strdup(var);
	}
}

int			ft_setenv(const char **av)
{
	extern	char	**environ;
	char			*p;
	char			*name;

	if (!environ)
		return (1);
	while (*av)
	{
		if ((p = ft_strchr(*av, '=')))
		{
			name = ft_strndup(*av, p - *av);
			if (!getenv(name))
				add_var(*av, &environ);
			else
				replace_var(name, *av, environ, p - *av);
			if (ft_strequ(name, "PATH"))
				fill_hash_table();
			free(name);
		}
		++av;
	}
	return (0);
}
