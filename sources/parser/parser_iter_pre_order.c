/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_iter_pre_order.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggwin-go <ggwin-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/01 21:06:39 by ggwin-go          #+#    #+#             */
/*   Updated: 2019/07/01 21:27:26 by ggwin-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

static void	iter_and_or(t_and_or *root)
{
	if (root->and_or)
		iter_and_or(root->and_or);
	printf("%s\n", root->pipeline);
	if ()
}

void	parser_iter_pre_order(t_pars_list *root)
{
	if (root->list)
		parser_iter_pre_order(root->list);
	while (1)
	{
		(void)root;
	}
}
int printf(char *format, ...);
