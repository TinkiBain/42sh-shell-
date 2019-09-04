/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggwin-go <ggwin-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/25 18:47:59 by ggwin-go          #+#    #+#             */
/*   Updated: 2019/09/04 16:00:18 by ggwin-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

static int	cmd_is_exist(const char *cmd)
{
	if (!get_bin((char *)cmd))
		return (return_error(cmd, "command not found"));
	return (0);
}

int			check_cmd(const char *cmd)
{
	const char		*p;
	extern char		**g_var;

	p = cmd;
	while (*p)
	{
		if (*p == '/')
			break ;
		else if (*p == '\\' && *(p + 1))
			++p;
		++p;
	}
	if (*p == '/' && (check_file_errors(cmd, X_OK)))
	{
		// set_var("?=127", &g_var, 1);
		return (g_res_exec);
	}
	else
		return (cmd_is_exist(cmd));
}
