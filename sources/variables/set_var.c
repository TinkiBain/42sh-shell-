/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_var.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggwin-go <ggwin-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/17 22:04:36 by ggwin-go          #+#    #+#             */
/*   Updated: 2019/08/31 23:30:10 by ggwin-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"
#include "hash.h"

static void	synchronize_var(const char *var, char **env, size_t name_len)
{
	extern char		**environ;
	extern char		**g_var;
	char			**tmp;

	tmp = NULL;
	if (env == environ)
		tmp = g_var;
	else if (env == g_var)
		tmp = environ;
	if (ft_getenv(var, tmp, name_len))
		replace_var(var, tmp, name_len);
}

static void	check_main_vars(const char *var, size_t name_len)
{
	extern t_history *g_history;

	if (name_len == 4 && ft_strnequ(var, "PATH", name_len))
		fill_hash_table();
	else if (g_history && name_len == 8 &&
									ft_strnequ(var, "HISTPATH", name_len))
	{
		free(g_history->path);
		g_history->path = ft_xstrdup(var + name_len + 1);
	}
	else if (g_history && name_len == 8 &&
									ft_strnequ(var, "HISTSIZE", name_len))
		g_history->size = ft_atoi(var + name_len + 1);
}

int			set_var(const char *var, char ***env, int change_readonly)
{
	const char	*tmp_var;
	char		*p;
	size_t		name_len;

	p = ft_strchr(var, '=');
	tmp_var = (p) ? var : (const char *)ft_strjoin(var, "=");
	if (env)
	{
		name_len = (p) ? (p - var) : ft_strlen(var);
		if (change_readonly || !check_readonly_var(tmp_var, name_len))
		{
			synchronize_var(tmp_var, *env, name_len);
			check_main_vars(tmp_var, name_len);
			if (!ft_getenv(tmp_var, *env, name_len))
				return (add_new_var(tmp_var, env));
			else
				return (replace_var(tmp_var, *env, name_len));
		}
	}
	if (!p)
		ft_memdel((void **)tmp_var);
	return (0);
}
