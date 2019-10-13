/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash_flag_r.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wtalea <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/26 17:40:27 by wtalea            #+#    #+#             */
/*   Updated: 2019/10/13 12:22:14 by wtalea           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

void	del_all_hash(void)
{
	extern	int		g_prog_names_count;
	extern	t_hash	**g_table;

	if (g_table)
		del_hash();
	g_prog_names_count = 0;
	g_table = (t_hash **)ft_xmalloc(sizeof(t_hash) * HASH_LEN);
	create_bin(get_var_value("PATH"));
	add_force_builds();
	create_arr_names();
}
