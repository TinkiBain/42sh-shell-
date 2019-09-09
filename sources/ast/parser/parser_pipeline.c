#include "parser.h"

/*
 ** Grammar rule
 ** pipeline         :      pipe_sequence
 **                  | Bang pipe_sequence
 **                  ;
*/

t_pipeline			*parser_free_pipeline(t_pipeline *list)
{
	if (!list)
		return (NULL);
	parser_free_pipe_sequence(list->pipe_sequence);
	free(list);
	return (NULL);
}

static t_pipeline	*parser_init_pipeline(void)
{
	t_pipeline		*list;

	list = (t_pipeline*)ft_xmalloc(sizeof(t_pipeline));
	list->bang = 0;
	list->pipe_sequence = NULL;
	return (list);
}

t_pipeline		*parser_pipeline(void)
{
	t_pipeline	*list;

	list = parser_init_pipeline();
	if (g_lex && g_lex->type == WORD && ft_strequ(g_lex->lexem, "!"))
	{
		list->bang = 1;
		g_lex = g_lex->next;
	}
	list->pipe_sequence = parser_pipe_sequence();
	if (g_error_lex)
		return (parser_free_pipeline(list));
	return (list);
}
