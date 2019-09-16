/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_dquote.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwisoky <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 15:02:30 by dwisoky           #+#    #+#             */
/*   Updated: 2019/09/16 15:41:09 by dwisoky          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h'

char	*parser_dquote(char *str, char **new_str)
{
	char	*begin;

	++str;
	while (*str != '\'')
	{
		if (!*str)
		{
			*new_str = ft_strrejoin(*new_str, ft_strndup(begin, str - begin), 3);
			str = parser_recall_readline(str);
			begin = str;
		}
		if (*str == '$')
			str = parser_dollar(str, new_str);
		else
			++str;
	}
	*new_str = ft_strrejoin(*new_str, ft_strndup(begin, str - begin), 3);
	return (str);
}
