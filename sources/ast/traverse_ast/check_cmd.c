/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggwin-go <ggwin-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/25 18:47:59 by ggwin-go          #+#    #+#             */
/*   Updated: 2019/09/06 02:03:39 by ggwin-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

int			check_cmd(const char *cmd)
{
	extern char		**g_var;
	const char		*p;

	p = cmd;
	while (*p)
	{
		if (*p == '/')
			break ;
		else if (*p == '\\' && *(p + 1))
			++p;
		++p;
	}
	if (*p == '/')
		return ((check_file_errors(cmd, X_OK)) ? g_res_exec : 0);
	else if (!get_bin((char *)cmd))
	{
		print_error("command not found", cmd);
		return ((g_res_exec = 127));
	}
	return (0);
}
