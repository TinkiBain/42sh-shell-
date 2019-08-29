/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggwin-go <ggwin-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/26 17:25:18 by dwisoky           #+#    #+#             */
/*   Updated: 2019/08/29 17:21:16 by ggwin-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

static int	lexer_check_separator(char *str)
{
	if (*str == ';')
		return (1);
	if (*str == '&')
		if (*(str + 1) && (*(str + 1) != '&' && *(str + 1) != '>'))
			return (1);
	return (0);
}

void		print_error_pars(t_lex *lex)
{
	ft_putstr_fd(g_project_name, 2);
	ft_putstr_fd(": syntax error near unexpected token `", 2);
	if (lex->type & SEMICOLON && lex->prev && lex->prev->type & SEMICOLON)
		ft_putstr_fd(";;", 2);
	else if (lex->type & SEMICOLON)
		ft_putstr_fd(";", 2);
	else if (lex->type & OR_IF)
		ft_putstr_fd("||", 2);
	else if (lex->type & AND_IF)
		ft_putstr_fd("&&", 2);
	else if (lex->type & PIPE_SYMB)
		ft_putstr_fd("|", 2);
	ft_putendl_fd("'", 2);
}

int			lex_type_spec(int type)
{
	if (type & SEMICOLON || type & PIPE_SYMB || type & AND_IF ||
			type & OR_IF)
		return (1);
	return (0);
}

t_lex		*get_first_lex(t_lex *lex)
{
	while (lex->prev)
	{
		if (lex_type_spec(lex->type) && lex_type_spec(lex->prev->type))
		{
			print_error_pars(lex);
			while (lex->next)
				lex = lex->next;
			lexer_free_all(lex);
			return (NULL);
		}
		lex = lex->prev;
	}
	return (lex);
}

t_lex		*lexer(char *buf)
{
	t_lex	*lex;

	lex = init_lex(NULL);
	while (*buf)
	{
		if (ft_isspace(*buf) && ++buf)
			continue ;
		if (*buf == '|' && ((*(buf + 1) && *(buf + 1) != '|')
							|| !*(buf + 1)) && ++buf)
			lex->type = PIPE_SYMB;
		else if (lexer_check_separator(buf) && ++buf)
			lex->type = SEMICOLON;
		else if (*buf == '!' && ft_isspace(*(buf + 1)))
			buf = lexer_bang(buf, lex);
		else
			buf = lexer_get_token(buf, &lex);
		lex->next = init_lex(lex);
		lex = lex->next;
	}
	lex = lex->prev;
	free(lex->next);
	lex->next = NULL;
	lex = get_first_lex(lex);
	return (lex);
}
