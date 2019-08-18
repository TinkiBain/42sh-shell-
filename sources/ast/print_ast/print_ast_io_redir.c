/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ast_io_redir.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggwin-go <ggwin-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/18 22:49:39 by ggwin-go          #+#    #+#             */
/*   Updated: 2019/08/18 22:56:47 by ggwin-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "print_ast.h"

void	print_ast_io_redir(t_io_redirect *redir)
{
	write(1, " ", 1);
	ft_putnbr(redir->io_number);
	print_ast_token_number(redir->type);
	ft_putstr(redir->file_name);
	write(1, " ", 1);
}
