/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_var.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggwin-go <ggwin-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/17 22:04:36 by ggwin-go          #+#    #+#             */
/*   Updated: 2019/09/08 20:15:53 by ggwin-go         ###   ########.fr       */
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
		replace_var(var, tmp, name_len, 0);
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

static int	handle_set_var(const char *var, size_t name_len,
												char ***env, int flag)
{
	synchronize_var(var, *env, name_len);
	check_main_vars(var, name_len);
	if (!ft_getenv(var, *env, name_len))
		return (add_new_var(var, env, flag));
	else
		return (replace_var(var, *env, name_len, flag));
}

int			set_var(const char *var, char ***env, int change_readonly)
{
	const char	*tmp_var;
	char		*p;
	size_t		name_len;
	int			flag;

	flag = 0;
	if (env && (tmp_var = var))
	{
		p = ft_strchr(var, '=');
		name_len = (p) ? (p - var) : ft_strlen(var);
		if (!p && (p = get_var_value((char *)var)))
		{
			flag = 1;
			tmp_var = (const char *)ft_strjoin(var, "=");
			tmp_var = (const char *)ft_strrejoin(tmp_var, p, 1);
		}
		else if (!p && (flag = 1))
			tmp_var = (const char *)ft_strjoin(var, "=");
		if (change_readonly || !check_readonly_var(tmp_var, name_len))
			handle_set_var(tmp_var, name_len, env, flag);
	}
	if (flag)
		ft_memdel((void **)tmp_var);
	return (0);
}
