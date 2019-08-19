/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_hash_table.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggwin-go <ggwin-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/03 17:49:40 by ggwin-go          #+#    #+#             */
/*   Updated: 2019/08/19 16:39:03 by wtalea           ###   ########.fr       */
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
	g_table = (t_hash **)ft_xmalloc(sizeof(t_hash) * HASH_LEN);
	create_bin(get_value_from_all_vars("PATH"));
	add_force_builds();
	create_arr_names();
}
