/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tdq_substitution.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwisoky <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 20:12:54 by dwisoky           #+#    #+#             */
/*   Updated: 2019/10/11 15:16:33 by gmelisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

char		*tdq_substitution(char *str)
{
	char	*new_str;
	char	*begin;

	new_str = ft_strnew(0);
	begin = str;
	while (*str)
	{
		if (*str == '\'' || *str == '"' || *str == '\\')
		{
			str = lexer_find_char(str, *str);
			++str;
		}
		else if (*str == '`' || ft_strnequ(str, "$(", 2))
		{
			new_str = ft_strrejoin(new_str, ft_xstrndup(begin, str - begin), 3);
			new_str = ft_strrejoin(new_str, substitution(str), 3);
			str = lexer_find_char(str, '`');
			++str;
			begin = str;
		}
		else
			++str;
	}
	new_str = ft_strrejoin(new_str, begin, 1);
	return (new_str);
}
