/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_case_clause.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwisoky <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 18:30:21 by dwisoky           #+#    #+#             */
/*   Updated: 2019/09/11 21:28:01 by dwisoky          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

/*
** Grammar rule
** case_clause      : Case WORD linebreak in linebreak case_list    Esac
**                  | Case WORD linebreak in linebreak case_list_ns Esac
** 		            | Case WORD linebreak in linebreak              Esac
**	                ;
*/

t_case_clause			*parser_free_case_clause(t_case_clause *list)
{
	if (!list)
		return (NULL);
	if (list->word)
		free(list->word);
	parser_free_case_list(list->case_list);
	free(list);
	return (NULL);
}

static t_case_clause	*parser_init_case_clause(void)
{
	t_case_clause		*list;

	list = (t_case_clause*)ft_xmalloc(sizeof(t_case_clause));
	list->word = ft_strdup(g_lex->lexem);
	g_lex = g_lex->next;
	parser_linebreak();
	list->case_list = NULL;
	return (list);
}

t_case_clause			*parser_case_clause(void)
{
	t_case_clause		*list;

	g_lex = g_lex->next;
	if (g_lex->type != WORD)
	{
		g_error_lex = g_lex;
		return (NULL);
	}
	list = parser_init_case_clause();
	if (g_lex->type != WORD || !ft_strequ(g_lex->lexem, "in"))
	{
		g_error_lex = g_lex;
		return (parser_free_case_clause(list));
	}
	g_lex = g_lex->next;
	parser_linebreak();
	list->case_list = parser_case_list();
	if (g_error_lex)
		return (parser_free_case_clause(list));
	if (g_lex->type != WORD || !ft_strequ(g_lex->lexem, "esac"))
	{
		g_error_lex = g_lex;
		return (parser_free_case_clause(list));
	}
	g_lex = g_lex->next;
	return (list);	
}
