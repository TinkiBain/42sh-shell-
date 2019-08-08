/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   traverse_cmd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggwin-go <ggwin-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/05 21:34:50 by ggwin-go          #+#    #+#             */
/*   Updated: 2019/08/08 22:26:27 by ggwin-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

static void	traverse_cmd_pref(t_cmd_prefix *pref, char ***env)
{
	while (pref)
	{
		if (pref->assignment_word)
			handle_token_assignment_word(pref->assignment_word, env);
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
	char			**new_env;
	extern char		**g_env;

	new_env = create_copy_env(g_env);
	av = (char **)ft_xmalloc(sizeof(char *) * 2);
	ft_bzero(av, sizeof(char *) * 2);
	pref = cmd->cmd_pref;
	if (pref)
	{
		traverse_cmd_pref(pref, &new_env);
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
		call_exec((const char **)av, &new_env);
	// ft_free_double_ptr_arr((void ***)&new_env);
	free(av);
}
