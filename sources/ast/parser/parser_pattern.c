/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_pattern.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggwin-go <ggwin-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 20:19:57 by dwisoky           #+#    #+#             */
/*   Updated: 2019/10/11 15:14:32 by gmelisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

/*
** Grammar rule
** pattern          :             WORD          Apply rule 4
**                  | pattern '|' WORD          Do not apply rule 4
**                  ;
*/

t_pattern			*parser_free_pattern(t_pattern *list)
{
	if (!list)
		return (NULL);
	parser_free_pattern(list->next_pattern);
	if (list->word)
		free(list->word);
	free(list);
	return (NULL);
}

static t_pattern	*parser_init_pattern(void)
{
	t_pattern		*list;

	list = (t_pattern*)ft_xmalloc(sizeof(t_pattern));
	list->next_pattern = NULL;
	list->word = NULL;
	return (list);
}

t_pattern			*parser_pattern(void)
{
	t_pattern		*list;

	if (ft_strequ(g_lex->lexem, "esac"))
	{
		g_error_lex = g_lex->next;
		return (NULL);
	}
	list = parser_init_pattern();
	list->word = ft_xstrdup(g_lex->lexem);
	g_lex = g_lex->next;
	if (g_lex->type == PIPE)
	{
		g_lex = g_lex->next;
		list = parser_pattern();
	}
	return (list);
}
