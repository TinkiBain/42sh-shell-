/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   traverse_io_redir.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggwin-go <ggwin-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/05 21:41:12 by ggwin-go          #+#    #+#             */
/*   Updated: 2019/08/05 21:46:21 by ggwin-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

void	traverse_io_redir(t_io_redirect *redir)
{
	ft_putnbr(redir->io_number);
	// print_token_number(redir->type);
	ft_putstr(redir->file_name);
	write(1, " ", 1);
}
