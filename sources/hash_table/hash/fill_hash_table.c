/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_hash_table.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggwin-go <ggwin-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/03 17:49:40 by ggwin-go          #+#    #+#             */
/*   Updated: 2019/08/08 14:03:04 by ggwin-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

void		fill_hash_table(void)
{
	extern t_hash	**g_table;
	extern char		**g_env;
	char			*p;

	if (g_table)
		del_hash();
	g_table = (t_hash **)ft_xmalloc(sizeof(t_hash) * HASH_LEN);
	if (g_env)
	{
		while (*g_env)
		{
			if (ft_strnequ("PATH=", *g_env, 5))
				break ;
			++g_env;
		}
		if (*g_env && (p = ft_strchr(*g_env, '=')))
			create_bin(p + 1);
	}
}
