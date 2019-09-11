/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   traverse_compound_command.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggwin-go <ggwin-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 19:24:51 by ggwin-go          #+#    #+#             */
/*   Updated: 2019/09/11 21:57:32 by ggwin-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

static int	if_subhell(t_if_clause *list, char **env)
{
	traverse_compound_list(list->if_head, env);
	if (!g_res_exec)
	{
		printf("res = 0\n");
		traverse_compound_list(list->if_body, env);
	}
	// else if (1)
	// {

	// }
	return (0);
}

void		traverse_compound_command(t_compound_cmd *cmd, char **env, int in_fork)
{
	if (cmd->if_clause)
		if_subhell(cmd->if_clause, env);
	else
		traverse_compound_list(cmd->compound_list, env);
		// cmd->if_clause
	(void)in_fork;
}
