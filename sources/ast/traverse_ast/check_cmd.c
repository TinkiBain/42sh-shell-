/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggwin-go <ggwin-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/25 18:47:59 by ggwin-go          #+#    #+#             */
/*   Updated: 2019/10/12 16:38:58 by ggwin-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

int			check_cmd(const char *cmd)
{
	extern char		**g_var;
	extern t_dict	*g_func_defs;
	const char		*p;

	p = cmd;
	if (ft_get_dict(g_func_defs, cmd))
		return (0);
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
		print_error(cmd, "command not found");
		return ((g_res_exec = 127));
	}
	return (0);
}
