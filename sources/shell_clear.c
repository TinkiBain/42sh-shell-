/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_clear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggwin-go <ggwin-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/27 01:25:17 by gmelisan          #+#    #+#             */
/*   Updated: 2019/09/12 20:44:46 by dwisoky          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

void		shell_clear(void)
{
	extern char		**environ;
	extern char		**g_var;
	extern char		**g_var_names;
	extern t_opt	g_opt;

	history_clear(g_history);
	del_hash();
	ft_free_double_ptr_arr((void ***)&environ);
	ft_free_double_ptr_arr((void ***)&g_var);
	ft_free_double_ptr_arr((void ***)&g_var_names);
	ft_memdel((void **)&g_project_name);
	alias_free_all();
	if (g_opt.rl_in != 0)
		close(g_opt.rl_in);
	else
		ft_putstr("exit\n");
	logclose();
}
