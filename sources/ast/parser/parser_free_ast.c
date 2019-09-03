#include "parser.h"

void		*parser_free_ast(t_pars_list *list)
{
	free(list);
	return (NULL);
}
