/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filter_variables.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelisan <gmelisan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/15 03:07:14 by gmelisan          #+#    #+#             */
/*   Updated: 2019/08/27 01:05:15 by gmelisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "actions.h"

void			filter_variables(t_string query, char ***start, int *n)
{
	extern char	**g_var_names;
	int			i;

	if (!start || !n)
		return ;
	*start = NULL;
	*n = 0;
	i = -1;
	while (g_var_names[++i])
	{
		if (ft_strnequ(query.s, g_var_names[i], query.len))
		{
			*start = &g_var_names[i];
			while (g_var_names[i] &&
					ft_strnequ(query.s, g_var_names[i], query.len))
			{
				*n += 1;
				i++;
			}
			return ;
		}
	}
}
