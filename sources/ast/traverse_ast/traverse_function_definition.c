/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   traverse_function_definition.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggwin-go <ggwin-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 20:20:23 by ggwin-go          #+#    #+#             */
/*   Updated: 2019/10/12 20:14:31 by ggwin-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

void	traverse_function_definition(t_func_definition *func)
{
	t_compound_cmd	*cmd;
	t_redirect_list	*redir_list;
	char			*tmp;
	extern t_dict	*g_func_defs;
	t_dict			*dict;

	if (check_name(func->function_name))
		return ;
	cmd = func->function_body->compound_command;
	if ((redir_list = func->function_body->redirect_list))
		tmp = get_job_name(cmd->begin_lex, redir_list->end_lex);
	else
		tmp = get_job_name(cmd->begin_lex, cmd->end_lex);
	if (!(dict = ft_get_dict(g_func_defs, func->function_name)))
	{
		dict = ft_init_dict(func->function_name, NULL);
		ft_dict_push_back(&g_func_defs, dict);
		fill_g_cmd_names();
	}
	dict->value = tmp;
	dict->value_len = ft_strlen(tmp);
}
