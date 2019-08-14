/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_pipeline.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggwin-go <ggwin-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/01 16:14:49 by ggwin-go          #+#    #+#             */
/*   Updated: 2019/07/26 20:23:01 by dwisoky          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static t_pipeline	*init_pipeline(void)
{
	t_pipeline	*pipeline;

	pipeline = (t_pipeline*)ft_xmalloc(sizeof(t_pipeline));
	pipeline->bang = 0;
	return (pipeline);
}

t_pipeline			*parser_pipeline(t_lex *lex)
{
	t_pipeline	*pipeline;
	extern int	g_error_pars;

	pipeline = init_pipeline();
	if (lex->type & BANG)
	{
		pipeline->bang = 1;
		lex = lex->next;
	}
	pipeline->pipe_sequence = parser_pipe_sequence(lex);
	if (!pipeline->pipe_sequence)
		return (parser_free_pipeline(pipeline));
	return (pipeline);
}
