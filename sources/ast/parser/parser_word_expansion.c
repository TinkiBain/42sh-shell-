/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_word_expansion.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwisoky <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 19:19:20 by dwisoky           #+#    #+#             */
/*   Updated: 2019/09/18 15:19:57 by dwisoky          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

char		*parser_sheilding(char *str)
{
	++str;
	if (*str)
	{
		++str;
		return (str);
	}
//	str = parser_recall_readline(str);
	return (str);
}

char		*parser_find_spec_simb(char *str, char **new_str)
{
	char	*begin;

	begin = str;
	while (*str)
	{
		if (*str == '\\')
			str = parser_sheilding(str);
		else if (*str == '`' || *str == '$' || *str == '\'' || *str == '"')
			break ;
		++str;
	}
	*new_str = ft_strrejoin(*new_str, ft_strndup(begin, str - begin), 3);
	return (str);
}

char		*parser_word_expansion(char *str)
{
	char	*new_str;

	if (!str)
		return (NULL);
	new_str = ft_strnew(0);
	while (*str)
	{
		if (*str == '`')
			str = parser_expansion_subshell(str, &new_str);
		else if (*str == '\'')
			str = parser_quote(str, &new_str);
		else if (*str == '"')
			str = parser_dquote(str, &new_str);
//		else if (*str == '$')
//			str = parser_dollar(str, &new_str);
		else
			str = parser_find_spec_simb(str, &new_str);
	}
	return (new_str);
}
