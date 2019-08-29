/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_clear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggwin-go <ggwin-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/27 01:25:17 by gmelisan          #+#    #+#             */
/*   Updated: 2019/08/29 18:55:23 by ggwin-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

void		shell_clear(void)
{
	extern char	**environ;
	extern char	**g_var;
	extern char	**g_var_names;

	del_hash();
	ft_free_double_ptr_arr((void ***)&environ);
	ft_free_double_ptr_arr((void ***)&g_var);
	ft_free_double_ptr_arr((void ***)&g_var_names);
	ft_memdel((void **)&g_project_name);
}
