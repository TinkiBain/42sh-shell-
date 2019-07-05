/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_io_redirect.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggwin-go <ggwin-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/05 21:12:56 by ggwin-go          #+#    #+#             */
/*   Updated: 2019/07/05 21:34:28 by ggwin-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

t_io_redirect	*init_io_redirect(void)
{
	t_io_redirect	*io_redir;

	io_redir = (t_io_redirect*)ft_xmalloc(sizeof(t_io_redirect));
	io_redir->file_name = NULL;
	io_redir->io_number = -1;
	io_redir->type = 0;
	return (io_redir);
}
