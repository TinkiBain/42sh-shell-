/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_pipeline.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggwin-go <ggwin-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/01 16:14:49 by ggwin-go          #+#    #+#             */
/*   Updated: 2019/07/04 17:25:29 by dwisoky          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

t_pipeline		*init_pipeline(void)
{
	t_pipeline	*pipeline;

	pipeline = (t_pipeline*)ft_xmalloc(sizeof(t_pipeline));
	pipeline->lexem = NULL;
	pipeline->bang = 0;
	return (pipeline);
}

t_pipeline		*parser_pipeline(t_lex **lex)
{
	t_pipeline	*pipeline;

	pipeline = init_pipeline();
	pipeline->lexem = *lex;
	return (pipeline);
}
