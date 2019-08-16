/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggwin-go <ggwin-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/17 22:04:36 by ggwin-go          #+#    #+#             */
/*   Updated: 2019/08/15 22:42:01 by ggwin-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"
#include "hash.h"

static void	add_var_to_environ(char *name, const char *var, char ***env, size_t len)
{
	if (!getenv(name))
		add_var(var, env);
	else
		replace_var(name, var, *env, len);
}

int			ft_setenv(const char **av)
{
	extern	char	**environ;
	char			*name;
	char			*p;
	size_t			len;

	if (!environ)
		return (1);
	while (*av)
	{
		if ((p = ft_strchr(*av, '=')))
		{
			len = p - *av;
			name = ft_strsub(*av, 0, len);
			if (!check_is_var_readonly(name))
			{
				add_var_to_environ(name, *av, &environ, len);
				if (len == 4 && ft_strnequ(name, "PATH", 5))
					fill_hash_table();
			}
			free(name);
		}
		++av;
	}
	return (0);
}
