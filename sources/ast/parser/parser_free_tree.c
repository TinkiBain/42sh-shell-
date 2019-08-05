/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_free_list.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwisoky <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/26 17:28:20 by dwisoky           #+#    #+#             */
/*   Updated: 2019/07/26 20:12:26 by dwisoky          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void		*parser_free_pipe_sequence(t_pipe_sequence *list)
{
	if (!list)
		return (NULL);
	if (list->cmd)
		parser_free_cmd(list->cmd);
	list->cmd = NULL;
	if (list->next)
		parser_free_pipe_sequence(list->next);
	list->next = NULL;
	free(list);
	list = NULL;
	return (NULL);
}

void		*parser_free_pipeline(t_pipeline *list)
{
	if (!list)
		return (NULL);
	if (list->pipe_sequence)
		parser_free_pipe_sequence(list->pipe_sequence);
	list->pipe_sequence = NULL;
	free(list);
	list = NULL;
	return (NULL);
}

void		*parser_free_and_or(t_and_or *list)
{
	if (!list)
		return (NULL);
	if (list->pipeline)
		parser_free_pipeline(list->pipeline);
	list->pipeline = NULL;
	if (list->and_or)
		parser_free_and_or(list->and_or);
	list->and_or = NULL;
	free(list);
	list = NULL;
	return (NULL);
}

void		*parser_free_tree(t_pars_list *list)
{
	if (!list)
		return (NULL);
	if (list->and_or)
		parser_free_and_or(list->and_or);
	list->and_or = NULL;
	if (list->list)
		parser_free_tree(list->list);
	list->list = NULL;
	free(list);
	list = NULL;
	return (NULL);
}
