/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   traverse_function_definition.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggwin-go <ggwin-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 20:20:23 by ggwin-go          #+#    #+#             */
/*   Updated: 2019/10/01 21:45:32 by ggwin-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

void	traverse_function_definition(t_func_definition *func, t_vector *funcs)
{
	t_compound_cmd	*cmd;
	t_redirect_list	*redir_list;
	char			*str;

	cmd = func->function_body->compound_command;
	if ((redir_list = func->function_body->redirect_list))
		str = get_job_name(cmd->begin_lex, redir_list->end_lex);
	else
		str = get_job_name(cmd->begin_lex, cmd->end_lex);
	printf("BASH_FUNC_%s%%%%=() {  %s\n}\n", func->function_name, str);
	funcs = vec_addback(funcs, func);
}
