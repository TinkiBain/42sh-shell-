/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_g_var.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggwin-go <ggwin-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/16 20:28:29 by ggwin-go          #+#    #+#             */
/*   Updated: 2019/08/25 17:28:39 by gmelisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "variables.h"
#include "defs.h"

static void	set_var_if_not_exist(char *var, char ***vars, int change_readolnly)
{
	char	*p;

	if ((p = ft_strchr(var, '=')) && !ft_getenv(var, *vars, p - var))
		set_var(var, vars, change_readolnly);
}

int			init_g_var(void)
{
	extern char		**environ;
	extern char		**g_var;
	char			*tmp;

	if (g_var)
		ft_free_double_ptr_arr((void ***)&g_var);
	if (environ)
		g_var = create_copy_env(environ);
	else
	{
		g_var = (char **)ft_xmalloc(sizeof(char *));
		ft_bzero(g_var, sizeof(char *));
	}
	set_var_if_not_exist("HISTPATH=~/.42sh.history", &g_var, 1);
	set_var_if_not_exist("HISTSIZE=20", &g_var, 1);
	set_var_if_not_exist("LOGPATH=~/.42sh.log", &g_var, 1);
	set_var_if_not_exist("PS1=" "\\033[0;31m" PROJECT_NAME ">\\033[0m ",
															&g_var, 1);
	set_var_if_not_exist("PS2=> ", &g_var, 1);
	tmp = ft_strrejoin("SHELLHOME=", getcwd(NULL, 1024), 2);
	set_var(tmp, &g_var, 1);
	ft_memdel((void **)&tmp);
	set_var("SHELLOPTS=", &g_var, 1);
	set_var_if_not_exist("TEXTEDITOR=/usr/bin/vim", &g_var, 1);
	return (0);
}
