/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_hash_table.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wtalea <wtalea@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/03 17:49:40 by wtalea            #+#    #+#             */
/*   Updated: 2019/10/14 01:52:41 by wtalea           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

void		fill_hash_table(void)
{
	extern	t_hash	**g_table;
	extern	int		g_prog_names_count;

	if (g_table)
		del_hash();
	g_prog_names_count = 0;
	g_table = (t_hash **)ft_xmemalloc(sizeof(t_hash) * HASH_LEN);
	create_bin(get_var_value("PATH"));
	add_force_builds();
	create_arr_names();
	add_flags_args();
}

void		fill_g_cmd_names(void)
{
	extern	char	**g_cmd_names;

	if (g_cmd_names)
		free(g_cmd_names);
	create_arr_names();
}
