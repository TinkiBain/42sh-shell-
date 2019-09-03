#include "parser.h"

/*
 ** Grammar rule
 **	newline_list     :              NEWLINE
 **	                 | newline_list NEWLINE
 **	                 ;
*/

void	parser_new_line_list(void)
{
	while (g_lex && g_lex->type == NEWLINE)
		g_lex = g_lex->next;
}
