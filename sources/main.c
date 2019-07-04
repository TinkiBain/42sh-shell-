/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggwin-go <ggwin-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/01 20:45:11 by ggwin-go          #+#    #+#             */
/*   Updated: 2019/07/04 19:22:52 by ggwin-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

void		print_pipeline(t_pipeline *pipeline)
{
	printf("	--PIPELINE--	\n");
	while (pipeline->lexem)
	{
		printf("%s\n", pipeline->lexem->lexeme);
		pipeline->lexem = pipeline->lexem->next;
	}
}

void		print_and_or(t_and_or *list)
{
	if (!list)
		return ;
	if (list->and_or)
		print_and_or(list->and_or);
	printf("	--AND_OR--	\n");
	printf("%d\n", list->and_or_if);
	print_pipeline(list->pipeline);
}

void		print_list(t_pars_list *list)
{
	if (!list)
		return ;
	if (list->list)
		print_list(list->list);
	printf("	--LIST--	\n");
	printf("%d\n", list->sep);
	if (list->and_or)
		print_and_or(list->and_or);
}

int			main(void)
{
	char		buf[1024];
	t_pars_list	*list;
	t_lex		*lex;
	char		*tmp;

	ft_putstr("------------------------\n");
	while (1)
	{
		buf[read(0, &buf, 1023) - 1] = '\0';
		if (ft_strequ("exit", buf))
			break ;
		if (*(tmp = ft_strtrim(buf)))
		{
			lex = lexer(buf);
			list = parser(&lex, NULL, 0);
			ast_iter_in_order(list);
			ft_putstr("\n------------------------\n");
			free(tmp);
		}
	}
	return (0);
}
