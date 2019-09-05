#include "parser.h"

int		parser_io_number(void)
{
	int	tmp;

	//добавить проверку преполнения
	tmp = ft_atoi(g_lex->lexem);
	g_lex = g_lex->next;
	return (tmp);
}
