/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_g_var.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggwin-go <ggwin-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/16 20:28:29 by ggwin-go          #+#    #+#             */
/*   Updated: 2019/10/27 16:32:13 by ggwin-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "variables.h"
#include "defs.h"
#include "xfuncs.h"

extern char	**g_var;

static void	set_var_if_not_exist(char *var, char ***vars, int change_readolnly)
{
	char	*p;

	if ((p = ft_strchr(var, '=')) && !ft_getenv(var, *vars, p - var))
		set_var(var, vars, change_readolnly);
}

static void	set_default_vars(void)
{
	char	*tmp;

	set_var_if_not_exist("HISTSIZE=" DEFAULT_HISTSIZE, &g_var, 1);
	set_var_if_not_exist("FCEDIT=/usr/bin/vim", &g_var, 1);
	set_var_if_not_exist("PS1=" DEFAULT_PROMPT, &g_var, 1);
	set_var_if_not_exist("PS2=heredoc> ", &g_var, 1);
	set_var_if_not_exist("PS3=> ", &g_var, 1);
	tmp = ft_xstrrejoin("SHELLHOME=", getcwd(NULL, 1024), 2);
	set_var(tmp, &g_var, 1);
	ft_memdel((void **)&tmp);
	set_var_shellopts();
	set_var_if_not_exist("TEXTEDITOR=/usr/bin/vim", &g_var, 1);
}

int			init_g_var(void)
{
	extern char		**environ;

	if (g_var)
		ft_free_ptr_array((void ***)&g_var);
	if (environ)
		g_var = create_copy_env(environ);
	else
	{
		g_var = (char **)ft_xmemalloc(sizeof(char *));
		ft_bzero(g_var, sizeof(char *));
	}
	set_default_vars();
	remove_var("OLDPWD", &g_var);
	remove_var("OLDPWD", &environ);
	return (0);
}
