/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   traverse_case_clause.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggwin-go <ggwin-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/23 19:07:01 by ggwin-go          #+#    #+#             */
/*   Updated: 2019/09/30 20:27:52 by ggwin-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

void			traverse_case_clause(t_case_clause *list, t_pjobs *local)
{
	t_case_list	*elem;
	t_pattern	*pattern;
	char		*target;

	list->word = tdq(list->word);
	elem = list->case_list;
	target = list->word;
	while (elem)
	{
		pattern = elem->case_item->pattern;
		while (pattern)
		{
			if (ft_strequ(target, pattern->word) ||
				(ft_strequ(pattern->word, "*")))
			{
				traverse_compound_list(elem->case_item->compound_list, local);
				return ;
			}
			pattern = pattern->next_pattern;
		}
		elem = elem->next;
	}
}
