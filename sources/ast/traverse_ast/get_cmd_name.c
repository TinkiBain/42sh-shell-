/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cmd_name.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggwin-go <ggwin-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 17:24:39 by ggwin-go          #+#    #+#             */
/*   Updated: 2019/09/09 17:24:47 by ggwin-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

char		*get_cmd_name(t_simple_cmd *cmd)
{
	if (cmd->cmd_pref)
	{
		if (cmd->cmd_word)
		{
			cmd->cmd_word = tdq(cmd->cmd_word);
			return (cmd->cmd_word);
		}
	}
	else
	{
		cmd->cmd_name = tdq(cmd->cmd_name);
		return (cmd->cmd_name);
	}
	return (NULL);
}
