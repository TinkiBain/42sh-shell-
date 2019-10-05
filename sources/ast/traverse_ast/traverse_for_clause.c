/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   traverse_for_clause.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggwin-go <ggwin-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 19:11:03 by ggwin-go          #+#    #+#             */
/*   Updated: 2019/10/05 20:54:18 by ggwin-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

void			traverse_for_clause(t_for_clause *list, t_pjobs *local)
{
	extern char	**g_var;
	char		*var_name;
	char		*var;
	t_wordlist	*wordlist;

	var_name = ft_strjoin(list->name, "=");
	if (check_readonly_var(var_name, ft_strlen(var_name)))
		return ;
	wordlist = list->wordlist;
	while (wordlist)
	{
		wordlist->word = tdq(wordlist->word);
		var = ft_strjoin(var_name, wordlist->word);
		set_var(var, &g_var, 0);
		ft_strdel(&var);
		traverse_compound_list(list->do_group, local);
		wordlist = wordlist->next;
	}
}
