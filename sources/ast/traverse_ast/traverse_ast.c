/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   traverse_ast.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jterry <jterry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/04 19:23:21 by ggwin-go          #+#    #+#             */
/*   Updated: 2019/09/08 16:37:43 by jterry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

static void		traverse_pipeline(t_pipeline *elem, t_pjobs *local)
{
	extern char	**environ;

	traverse_pipe_sequence(elem->pipe_sequence, environ, local);
	if (elem->bang)
		g_res_exec = (!g_res_exec) ? 1 : 0;
}

static void		traverse_and_or(t_and_or *elem, int flag1, t_pjobs *local)
{
	static int	flag;

	flag = flag1;
	if (elem->next)
		traverse_and_or(elem->next, flag, local);
	if (WIFEXITED(g_res_exec))
		g_res_exec = WEXITSTATUS(g_res_exec);
	set_result();
	if (!flag || (flag == AND_IF && !g_res_exec)
				|| (flag == OR_IF && g_res_exec))
		traverse_pipeline(elem->pipeline, local);
	else
		return ;
	flag = elem->and_or_if;
}

static void		traverse_list(t_pars_list *list, t_pjobs *local)
{
	if (list->next)
		traverse_list(list->next, local);
	g_res_exec = 0;
	traverse_and_or(list->and_or, 0, local);
}

void			traverse_ast(t_complete_cmd *root)
{
	t_pjobs	*local;

	if (!root)
		return ;
	local = jobs_startet("name", root->sep);
	root->list->sep = root->sep;
	traverse_list(root->list, local);
}
