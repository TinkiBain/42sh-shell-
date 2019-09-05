/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filter_command_options.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelisan <gmelisan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 23:04:39 by gmelisan          #+#    #+#             */
/*   Updated: 2019/09/05 23:04:56 by gmelisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "actions.h"

void	filter_command_options(t_string command, t_string query,
									char ***start, int *n)
{
	int			i;
	char		**args;

	if (!start || !n)
		return ;
	*start = NULL;
	*n = 0;
	if (!(args = get_command_options(command.s)))
		return ;
	i = -1;
	while (args[++i])
	{
		if (ft_strnequ(query.s, args[i], query.len))
		{
			*start = &args[i];
			while (args[i] &&
					ft_strnequ(query.s, args[i], query.len))
			{
				*n += 1;
				i++;
			}
			return ;
		}
	}
}
