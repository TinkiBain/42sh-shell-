/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_less_and.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwisoky <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/08 14:57:05 by dwisoky           #+#    #+#             */
/*   Updated: 2019/08/08 15:07:55 by dwisoky          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

int		redir_less_and(t_io_redirect *redir)
{
	int	close;
	int right_fd;

	if (redir->io_number == -1)
		redir->io_number = 1;
	if (fill_fd(redir, &close, &right_fd) < 0)
		return (-1);
	if (redir->io_number > 2)
		return (redir_error_fd(redir->io_number));

}
