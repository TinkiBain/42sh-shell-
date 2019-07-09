/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_io_redirect.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggwin-go <ggwin-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/05 21:10:37 by ggwin-go          #+#    #+#             */
/*   Updated: 2019/07/09 18:02:07 by dwisoky          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

t_io_redirect	*init_io_redirect(void)
{
	t_io_redirect	*io_redir;

	io_redir = (t_io_redirect*)ft_xmalloc(sizeof(t_io_redirect));
	io_redir->file_name = NULL;
	io_redir->io_number = -1;
	io_redir->type = 0;
	return (io_redir);
}

t_io_redirect	*parser_io_redirect(t_lex *lex)
{
	t_io_redirect	*io_redir;

	printf("IO_REDIRECT\n");
	io_redir = init_io_redirect();
	if (lex->lexeme)
		io_redir->file_name = ft_strdup(lex->lexeme);
	if (lex->fd)
		io_redir->io_number = lex->fd;
	io_redir->type = lex->type;
	return (io_redir);
}
