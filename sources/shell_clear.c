/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_clear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggwin-go <ggwin-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/27 01:25:17 by gmelisan          #+#    #+#             */
/*   Updated: 2019/10/07 15:00:05 by ggwin-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

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
	else
		ft_putstr_fd("exit\n", 2);
	logclose();
}
