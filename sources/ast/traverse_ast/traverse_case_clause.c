/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   traverse_case_clause.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jterry <jterry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/23 19:07:01 by ggwin-go          #+#    #+#             */
/*   Updated: 2019/11/02 18:35:20 by jterry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

/*
** case_clause		: Case WORD linebreak in linebreak case_list    Esac
** 					| Case WORD linebreak in linebreak case_list_ns Esac
** 					| Case WORD linebreak in linebreak              Esac
** 					;
** case_list_ns		: case_list case_item_ns
** 					|           case_item_ns
** 					;
** case_list		: case_list case_item
** 					|           case_item
** 					;
** case_item_ns		:     pattern ')'               linebreak
** 					|     pattern ')' compound_list linebreak
** 					| '(' pattern ')'               linebreak
** 					| '(' pattern ')' compound_list linebreak
** 					;
** case_item		:     pattern ')' linebreak     DSEMI linebreak
** 					|     pattern ')' compound_list DSEMI linebreak
** 					| '(' pattern ')' linebreak     DSEMI linebreak
** 					| '(' pattern ')' compound_list DSEMI linebreak
** 					;
** pattern		 	:             WORD
** 					| pattern '|' WORD
*/

void			traverse_case_clause(t_case_clause *list, t_pjobs **local)
{
	t_case_list	*elem;
	t_pattern	*pattern;
	char		*target;

	deletejob(&g_cur_job, 1);
	list->word = tdq(list->word, local);
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
				traverse_compound_list(elem->case_item->compound_list);
				return ;
			}
			if (g_is_interrupt)
				return ;
			pattern = pattern->next_pattern;
		}
		elem = elem->next;
	}
}
