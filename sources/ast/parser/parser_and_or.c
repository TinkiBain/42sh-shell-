#include "parser.h"

/*
 ** Grammar rule
 ** and_or           :                         pipeline
 **		             | and_or AND_IF linebreak pipeline
 **                  | and_or OR_IF  linebreak pipeline
 **                  ;
*/

t_and_or		*parser_free_and_or(t_and_or *list)
{
	if (!list)
		return (NULL);
	parser_free_pipeline(list->pipeline);
	parser_free_and_or(list->and_or);
	free(list);
	return (NULL);
}

static t_and_or	*parser_init_and_or(t_and_or *list_down)
{
	t_and_or	*list;

	list = (t_and_or*)ft_xmalloc(sizeof(t_and_or));
	list->and_or = list_down;
	list->and_or_if = 0;
	list->pipeline = NULL;
	return (list);
}

t_and_or		*parser_and_or(t_and_or *list_down)
{
	t_and_or	*list_and_or;

	list_and_or = parser_init_and_or(list_down);
	list_and_or->pipeline = parser_pipeline();
	if (g_error_lex)
		return (parser_free_and_or(list_and_or));
	if (!g_lex)
		return (list_and_or);
	if (g_lex->type == AND_IF || g_lex->type == OR_IF)
		list_and_or->and_or_if = g_lex->type;
	else
		return (list_and_or);
	g_lex = g_lex->next;
	parser_linebreak();
	return (parser_and_or(list_and_or));
}
