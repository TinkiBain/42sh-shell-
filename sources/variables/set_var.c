/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_var.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggwin-go <ggwin-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/17 22:04:36 by ggwin-go          #+#    #+#             */
/*   Updated: 2019/08/19 23:09:32 by ggwin-go         ###   ########.fr       */
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

static void	check_main_vars(char *name, const char *var, size_t len)
{
	extern t_history *g_history;

	if (len == 4 && ft_strnequ(name, "PATH", len))
		fill_hash_table();
	else if (g_history && len == 8 && ft_strnequ(var, "HISTPATH", len))
	{
			free(g_history->path);
			g_history->path = ft_xstrdup(var + len + 1);
	}
	else if (g_history && len == 8 && ft_strnequ(var, "HISTSIZE", len))
		g_history->size = ft_atoi(var + len + 1);
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
			check_main_vars(name, var, len);
			if (!ft_getenv(name, *env))
				return (add_new_var(var, env));
			else
				return (replace_var(name, var, *env, len));
		}
		free(name);
	}
	return (0);
}
