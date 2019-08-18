/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ast_token_assignment_word.c                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggwin-go <ggwin-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/18 22:59:01 by ggwin-go          #+#    #+#             */
/*   Updated: 2019/08/18 22:59:11 by ggwin-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "print_ast.h"

void	print_ast_token_assignment_word(char *word)
{
	ft_putstr("$(\'");
	ft_putstr(word);
	ft_putstr("\')");
}
