#include "parser.h"

/*  Grammar rule
 ** linebreak        : newline_list
 **                  | / empty /
 **                  ;
*/

void		parser_linebreak(void)
{
	parser_new_line_list();
//	if (!g_lex)
//	повторный вызов readline
}