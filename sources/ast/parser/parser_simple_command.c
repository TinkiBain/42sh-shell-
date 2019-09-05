#include "parser.h"

static char				*parser_simple_command_take_name(void)
{
	char		*tmp;

	if (!g_lex)
		return (NULL);
	if (g_lex->type == WORD)
	{
		tmp = g_lex->lexem;
		g_lex = g_lex->next;
		return (tmp);
	}
	return (NULL);
}

t_simple_cmd			*parser_free_simple_command(t_simple_cmd *list)
{
	if (!list)
		return (NULL);
	parser_free_cmd_prefix(list->cmd_pref);
	parser_free_cmd_suffix(list->cmd_suf);
	if (list->cmd_word)
		free(list->cmd_word);
	if (list->cmd_name)
		free(list->cmd_name);
	free(list);
	return (NULL);
}

static t_simple_cmd		*parser_init_simple_command(void)
{
	t_simple_cmd		*list;

	list = (t_simple_cmd*)ft_xmalloc(sizeof(t_simple_cmd));
	list->cmd_pref = NULL;
	list->cmd_name = NULL;
	list->cmd_word = NULL;
	list->cmd_suf = NULL;
	return (list);
}

t_simple_cmd			*parser_simple_command(void)
{
	t_simple_cmd		*list;

	list = parser_init_simple_command();
	list->cmd_pref = parser_cmd_prefix();
	if (list->cmd_pref)
		list->cmd_word = parser_simple_command_take_name();
	else
		list->cmd_name = parser_simple_command_take_name();
	list->cmd_suf = parser_cmd_suffix();
	if (!list->cmd_pref && !list->cmd_name)
	{
		g_error_lex = g_lex;
		return (parser_free_simple_command(list));
	}
	return (list);
}
