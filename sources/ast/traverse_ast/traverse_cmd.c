/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   traverse_cmd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggwin-go <ggwin-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/05 21:34:50 by ggwin-go          #+#    #+#             */
/*   Updated: 2019/08/06 18:07:37 by ggwin-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

static void	traverse_cmd_pref(t_cmd_prefix *pref)
{
	while (pref)
	{
		if (pref->assignment_word)
			handle_token_assignment_word(pref->assignment_word);
		else
			redirect(pref->io_redir);
		pref = pref->cmd_pref;
	}
}

void		traverse_cmd(t_cmd *cmd)
{
	t_cmd_suffix	*suff;
	t_cmd_prefix	*pref;
	char			**av;
	extern char		**environ;

	av = (char**)ft_xmalloc(sizeof(char*) * (1));
	*av = NULL;
	pref = cmd->cmd_pref;
	if (pref)
	{
		traverse_cmd_pref(pref);
		if (cmd->cmd_word)
			push_back_av(&av, cmd->cmd_word);
	}
	else
		push_back_av(&av, cmd->cmd_name);
	suff = cmd->cmd_suf;
	while (suff)
	{
		if (suff->word)
			push_back_av(&av, suff->word);
		else
			redirect(suff->io_redir);
		suff = suff->cmd_suf;
	}
	if (*av)
		call_exec(av, &environ);
	free(av);
}
