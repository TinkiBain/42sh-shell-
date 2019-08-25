/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_commands.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelisan <gmelisan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/19 17:04:53 by gmelisan          #+#    #+#             */
/*   Updated: 2019/08/25 18:12:29 by gmelisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "actions.h"

void			get_commands(t_string query, char ***start, int *n)
{
	extern char	**g_cmd_names;
	int			i;

	if (!start || !n)
		return ;
	*start = NULL;
	*n = 0;
	i = -1;
	while (g_cmd_names[++i])
	{
		if (ft_strnequ(query.s, g_cmd_names[i], query.len))
		{
			*start = &g_cmd_names[i];
			while (g_cmd_names[i] &&
					ft_strnequ(query.s, g_cmd_names[i], query.len))
			{
				*n += 1;
				i++;
			}
			return ;
		}
	}
}
