#include "lexer.h"

char		*lexer_find_char(char *str, char c)
{
	++str;
	while (*str && *str != c)
	{
		if (*str == '\\' && c != '\'')
		{
			++str;
			if (!*str)
				return (str);
			++str;
		}
		++str;
	}
	return (str);
}

char		*lexer_find_word(char *str, t_lex **lex)
{
	char	*begin;

	begin = str;
	while (*str)
	{
		if (ft_isspace(*str))
			break ;
		else if (lexer_check_spec_symbol(*str))
			break ;
		if (*str == '\'' || *str == '"')
			str = lexer_find_char(str, *str);
		else if (*str == '\\')
		{
			++str;
			if (!*str)
				break ;
			++str;
		}
		++str;
	}
	begin = ft_strndup(begin, str - begin);
	if (lexer_check_reserved_word(begin, lex))
		return (str);
	else
		init_lex(WORD, begin, lex);
	return (str);
}
