#include "parser.h"

/*
 ** Grammar rule
 ** pipe_sequence    :                             command
 **                  | pipe_sequence '|' linebreak command
 **                  ;
*/

t_pipe_sequence		*parser_free_pipe_sequence(t_pipe_sequence *list)
{
	if (!list)
		return (NULL);
	parser_free_command(list->command);
	parser_free_pipe_sequence(list->next);
	free(list);
	return (NULL);
}

t_pipe_sequence		*parser_init_pipe_sequence(t_pipe_sequence *list_down)
{
	t_pipe_sequence	*list;

	list = (t_pipe_sequence*)ft_xmalloc(sizeof(t_pipe_sequence));
	list->next = list_down;
	list->cmd = NULL;
	return (list);
}

t_pipe_sequence		*parser_pipe_sequence(t_pipe_sequence *list_down)
{
	t_pipe_sequence	*list;

	list = parser_init_pipe_sequence(list_down);
	list->command = parser_command();
	if (!g_lex)
		return (list);
	if (g_lex->type == PIPE)
	{
		g_error_lex = NULL;
		g_lex = g_lex->next;
		return (parser_pipe_sequence(list));
	}
	else
		g_error_lex = g_lex;
	return (parser_free_pipe_sequence(list));
}
