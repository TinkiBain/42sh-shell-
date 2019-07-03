/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_iter_in_order.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggwin-go <ggwin-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/01 21:06:39 by ggwin-go          #+#    #+#             */
/*   Updated: 2019/07/02 22:15:50 by ggwin-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

static void	print_token_word(char *word)
{
	ft_putstr("\'");
	ft_putstr(word);
	ft_putstr("\'");
}

static void	print_token_number(int number)
{
	ft_putstr("_");
	ft_putnbr(number);
	ft_putstr("_");
}

static void	pipeline_iter(t_pipeline *root)
{
	if (root->bang)
		ft_putstr("!");
	// error buttom this line (root->lexem == NULL)
	if (root->lexem)
		print_token_word(root->lexem->lexeme);
}

static void	and_or_iter_in_order(t_and_or *root)
{
	if (root->and_or)
	{
		and_or_iter_in_order(root->and_or);
		if (root->and_or_if == AND_IF || root->and_or_if == OR_IF)
			print_token_number(root->and_or_if);
	}
	pipeline_iter(root->pipeline);
}

void	parser_iter_in_order(t_pars_list *root)
{
	if (!root)
		return ;
	if (root->list)
	{
		parser_iter_in_order(root->list);
		if (root->sep)
			print_token_number(root->sep);
	}
	if (root->and_or)
		and_or_iter_in_order(root->and_or);
}
