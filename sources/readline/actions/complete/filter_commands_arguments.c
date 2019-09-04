/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filter_commands_arguments.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelisan <gmelisan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 19:05:13 by gmelisan          #+#    #+#             */
/*   Updated: 2019/09/04 19:07:23 by gmelisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "actions.h"

void	filter_command_arguments(t_string query, char ***start, int *n)
{
	int			i;
	char		**args;

	if (!start || !n)
		return ;
	args = hash_get_flags(query.s);
	*start = NULL;
	*n = 0;
	i = -1;
	while (args[++i])
	{
		if (ft_strnequ(query.s, args[i], query.len))
		{
			*start = &args[i];
			while (g_cmd_names[i] &&
					ft_strnequ(query.s, args[i], query.len))
			{
				*n += 1;
				i++;
			}
			return ;
		}
	}
}
