/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_var.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggwin-go <ggwin-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/17 22:04:36 by ggwin-go          #+#    #+#             */
/*   Updated: 2019/08/18 20:59:10 by ggwin-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"
#include "hash.h"

static void	synchronize_var(char *name, const char *var, char **env, size_t len)
{
	extern char		**environ;
	extern char		**g_var;
	char			**tmp;

	tmp = NULL;
	if (env == environ)
		tmp = g_var;
	else if (env == g_var)
		tmp = environ;
	if (ft_getenv(name, tmp))
		replace_var(name, var, tmp, len);
}

int			set_var(const char *var, char ***env, int change_readonly)
{
	char	*name;
	size_t	len;

	if (env && (name = get_var_name(var, &len)))
	{
		if (change_readonly || !check_readonly_var(name))
		{
			synchronize_var(name, var, *env, len);
			if (!ft_getenv(name, *env))
				return (add_new_var(var, env));
			else
				return (replace_var(name, var, *env, len));
			if (len == 4 && ft_strnequ(name, "PATH", 5))
			{
				fill_hash_table();
			}
		}
		free(name);
	}
	return (0);
}
