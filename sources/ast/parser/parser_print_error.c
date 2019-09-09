/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_print_error.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwisoky <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 19:09:52 by dwisoky           #+#    #+#             */
/*   Updated: 2019/09/09 22:05:28 by dwisoky          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "defs.h"

static void		parser_print_error_lexem(char *lex)
{
	ft_putstr_fd(": syntax error near unexpected token `", 2);
	ft_putstr_fd(lex, 2);
	ft_putstr_fd("'\n", 2);
}

static void	parser_print_error_token(int type)
{
	ft_putstr_fd(": syntax error near unexpected token `", 2);
	if (type == NEWLINE)
		write(1, "newline", 7);
	else if (type == SEMI)
		write(1, ";", 1);
	else if (type == DSEMI)
		write(1, ";;", 2);
	else if (type == AND_IF)
		write(1, "&&", 2);
	else if (type == OR_IF)
		write(1, "||", 2);
	else if (type == PIPE)
		write(1, "|", 1);
	else if (type == JOB)
		write(1, "&", 1);
	else if (type == LBRACKET)
		write(1, "(", 1);
	else
		write(1, ")", 1);
	ft_putstr_fd("'\n", 2);
}

static void	parser_print_redirect_error(int type)
{
	ft_putstr_fd(": syntax error near unexpected token `", 2);
	if (type == ANDGREAT)
		write(1, "&>", 2);
	else if (type == ANDDGREAT)
		write(1, "&>>", 3);
	else if (type == ANDLESS)
		write(1, "&<", 2);
	else if (type == CLOBBER)
		write(1, ">|", 2);
	else if (type == GREAT)
		write(1, ">", 1);
	else if (type == DGREAT)
		write(1, ">>", 2);
	else if (type == GREATAND)
		write(1, "&>", 2);
	else if (type == LESS)
		write(1, "<", 1);
	else if (type == DLESS)
		write(1, "<<", 2);
	else if (type == TLESS)
		write(1, "<<<", 3);
	else if (type == DLESSDASH)
		write(1, "<<-", 3);
	else if (type == LESSAND)
		write(1, "<&", 2);
	else if (type == DLESSAND)
		write(1, "<<&", 3);
	else
		write(1, "<>", 2);
	ft_putstr_fd("'\n", 2);
}

void		parser_print_error(void)
{
	if (!g_error_lex)
		return ;
	ft_putstr_fd(g_project_name, 2);
	if (g_error_lex->type == WORD || g_error_lex->type == IO_NUMBER)
		parser_print_error_lexem(g_error_lex->lexem);
	else if (g_error_lex->type >= ANDGREAT
			&& g_error_lex->type <= DLESSAND)
		parser_print_redirect_error(g_error_lex->type);
	else if ((g_error_lex->type >= NEWLINE && g_error_lex->type <= JOB) ||
			(g_error_lex->type == LBRACKET || g_error_lex->type == RBRACKET))
		parser_print_error_token(g_error_lex->type);
	else if (g_error_lex->type == EOF)
		ft_putstr_fd(": syntax error: unexpected end of file\n", 2);
	return ;
}
