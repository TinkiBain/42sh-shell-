/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   traverse_redirections.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggwin-go <ggwin-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 18:47:46 by ggwin-go          #+#    #+#             */
/*   Updated: 2019/09/13 22:36:16 by ggwin-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

// void test(t_vector *vec)
// {
// 	char *new;

// 	new = "abc";
// 	vec_xaddback(vec, &new);
// 	vec->len;
// 	(char **)vec->v;
// }

static int	traverse_redirections_in_simple_cmd(t_simple_cmd *cmd)
{
	// t_vector		vec;
	t_cmd_prefix	*pref;
	t_cmd_suffix	*suff;
	int				res;

	pref = cmd->cmd_pref;
	while (pref)
	{
		if (!(pref->assignment_word) && (res = redirect(pref->io_redir)) == -1)
			return (-1);
		pref = pref->cmd_pref;
	}
	suff = cmd->cmd_suf;
	while (suff)
	{
		if (!suff->word && (res = redirect(suff->io_redir)) == -1)
			return (-1);
		suff = suff->cmd_suf;
	}
	return (res);
}

int			traverse_redirections(t_command *cmd)
{
	redir_set();
	if (cmd->simple_command)
		return (traverse_redirections_in_simple_cmd(cmd->simple_command));
	else if (cmd->redirect_list)
		return (traverse_redirect_list(cmd->redirect_list));
	return (-1);
	// redir_reset();
}
