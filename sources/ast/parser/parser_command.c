#include "parser.h"

/*
 ** Grammar rule
 ** command          : simple_command
 **                  | compound_command
 **                  | compound_command redirect_list
 **                  | function_definition
 **                  ;
*/

t_command			*parser_free_command(t_command *list)
{
	if (!list)
		return (NULL);
	parser_free_simple_command(list->simple_command);
	free(list);
	return (NULL);
}

static t_command	*parser_init_command(void)
{
	t_command		*list;

	list = (t_command*)ft_xmalloc(sizeof(t_command));
	list->simple_command = NULL;
	list->compaund_command = NULL;
	return (list);
}

t_command	*parser_command(void)
{
	t_command	*list;

	list = parser_init_command();
	list->simple_command = parser_simple_command();
	if (g_error_lex)
		return (parser_free_command(list));
	return (list);
}
