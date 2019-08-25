/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_check_redir.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggwin-go <ggwin-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/29 18:39:22 by dwisoky           #+#    #+#             */
/*   Updated: 2019/08/25 19:16:56 by dwisoky          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

int			lexer_redir_and(char **str)
{
	(*str)++;
	if (**str && **str == '>' && ++(*str))
	{
		if (**str && **str == '>' && ++(*str))
			return (ANDDGREAT);
		return (ANDGREAT);
	}
	(*str)--;
	return (0);
}

int			lexer_redir_great(char **str)
{
	(*str)++;
	if (**str && **str == '|' && ++(*str))
		return (CLOBBER);
	if (**str && **str == '>' && ++(*str))
		return (DGREAT);
	if (**str && **str == '&' && ++(*str))
		return (GREATAND);
	return (GREAT);
}

int			lexer_redir_less(char **str)
{
	(*str)++;
	if (**str && (**str) == '<' && ++(*str))
	{
		if (**str && (**str) == '-' && ++(*str))
			return (DLESSDASH);
		if (**str && (**str) == '<' && ++(*str))
			return (TLESS);
		else
			return (DLESS);
	}
	if (**str && (**str) == '&' && ++(*str))
		return (LESSAND);
	if (**str && (**str) == '>' && ++(*str))
		return (LESSGREAT);
	return (LESS);
}

size_t		lexer_fill_redir_right(char *str, t_lex **lex)
{
	char	*begin;

	begin = str;
	while (*str && !ft_isspace(*str) && !ft_isspec(*str))
	{
		if (*str == '\\')
		{
			++str;
			if (*str)
				++str;
			else
				break ;
		}
		if (*str == '-')
		{
			++str;
			break ;
		}
		++str;
	}
	(*lex)->lexeme = ft_strndup(begin, str - begin);
	return (str - begin);
}

size_t		lexer_check_redir(char *str, t_lex **lex)
{
	char	*begin;
	int		fd;
	int		type;

	fd = 0;
	begin = str;
	str = get_left_fd(str, &fd);
	if (begin == str)
		fd = -1;
	type = 0;
	if (!lexer_return_type(&str, &type))
		return (0);
	if (type == 0)
		return (0);
	while (*str && ft_isspace(*str))
		++str;
	if (type & GREATAND || type & LESSAND)
		str += lexer_fill_redir_right(str, lex);
	else
		str += lexer_check_word(str, lex);
	(*lex)->fd = fd;
	(*lex)->type = type;
	return (str - begin);
}
