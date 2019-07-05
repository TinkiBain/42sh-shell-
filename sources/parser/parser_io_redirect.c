/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_io_redirect.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggwin-go <ggwin-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/05 21:10:37 by ggwin-go          #+#    #+#             */
/*   Updated: 2019/07/05 22:25:56 by ggwin-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

t_io_redirect	*parser_io_redirect(t_lex *lex)
{
	t_io_redirect	*io_redir;

	io_redir = init_io_redirect();
	if (lex->lexeme)
		io_redir->file_name = lex->lexeme;
	if (lex->fd)
		io_redir->io_number = lex->fd;
	io_redir->type = lex->type;
	return (io_redir);
}
