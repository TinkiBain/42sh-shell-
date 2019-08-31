#include "lexer.h"

void		lexer_free_all(t_lex *lex)
{
	t_lex	*tmp;

	while (lex)
	{
		tmp = lex->next;
		if (lex->lexem)
			free(lex->lexem);
		free(lex);
		lex = tmp;
	}
}
