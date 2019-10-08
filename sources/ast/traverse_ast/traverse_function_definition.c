/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   traverse_function_definition.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggwin-go <ggwin-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 20:20:23 by ggwin-go          #+#    #+#             */
/*   Updated: 2019/10/08 17:50:54 by ggwin-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

void	traverse_function_definition(t_func_definition *func)
{
	t_compound_cmd	*cmd;
	t_redirect_list	*redir_list;
	char			*str;
	char			*tmp;
	extern char		**g_func_defs;

	if (check_name(func->function_name))
		return ;
	cmd = func->function_body->compound_command;
	str = ft_xstrjoin(func->function_name, "={ ");
	if ((redir_list = func->function_body->redirect_list))
		tmp = get_job_name(cmd->begin_lex, redir_list->end_lex);
	else
		tmp = get_job_name(cmd->begin_lex, cmd->end_lex);
	str = ft_strrejoin(str, tmp, 3);
	str = ft_strrejoin(str, "\n}", 1);
	set_var((const char *)str, &g_func_defs, 0);
	ft_strdel(&str);
}
