/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_clear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggwin-go <ggwin-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/27 01:25:17 by gmelisan          #+#    #+#             */
/*   Updated: 2019/10/09 15:15:49 by gmelisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

void		print_exit(void)
{
	extern t_opt	g_opt;

	if (!g_opt.rl_gnl)
		ft_putstr_fd("exit\n", 2);
}

void		shell_clear(void)
{
	extern char		**environ;
	extern char		**g_var;
	extern char		**g_func_defs;
	extern char		**g_var_names;
	extern t_opt	g_opt;

	history_save(g_history);
	history_clear(g_history);
	del_hash();
	ft_free_ptr_array((void ***)&environ);
	ft_free_ptr_array((void ***)&g_var);
	ft_free_ptr_array((void ***)&g_var_names);
	ft_free_ptr_array((void ***)&g_func_defs);
	ft_memdel((void **)&g_project_name);
	ft_memdel((void **)&g_shell_path);
	alias_free_all();
	if (g_opt.rl_gnl != 0)
		close(g_opt.rl_in);
	logclose();
}
