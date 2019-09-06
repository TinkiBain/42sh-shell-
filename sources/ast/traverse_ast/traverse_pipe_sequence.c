/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   traverse_pipe_sequence.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggwin-go <ggwin-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 19:46:45 by ggwin-go          #+#    #+#             */
/*   Updated: 2019/09/06 20:43:48 by ggwin-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

void		traverse_pipe_sequence(t_pipe_sequence *elem)
{
	if (elem->next)
		traverse_pipe_sequence(elem->next);
	printf("%d\n", elem->pipe_op);
}
