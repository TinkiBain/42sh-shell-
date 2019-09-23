/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggwin-go <ggwin-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 17:15:05 by dwisoky           #+#    #+#             */
/*   Updated: 2019/09/23 20:46:07 by ggwin-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"
#include "ast.h"
#include <sys/ioctl.h>

int		redirect(t_io_redirect *redir)
{
	// redir_set();
	if (redir->io_number == -2 && !(redir->type == GREATAND))
		return (redirect_error_range_fd());
	if (redir->type == LESS)
		return (redir_less(redir));
	else if (redir->type == DLESS)
		return (redir_dless(redir));
	else if (redir->type == DLESSDASH)
		return (redir_dless(redir));
	else if (redir->type == TLESS)
		return (redir_tless(redir));
	else if (redir->type == LESSAND)
		return (redir_less_and(redir));
	else if (redir->type == LESSGREAT)
		return (redir_less_great(redir));
	else if (redir->type == GREAT || redir->type & DGREAT)
		return (redir_great(redir));
	else if (redir->type == GREATAND)
		return (redir_great_and(redir));
	else if (redir->type == ANDGREAT)
		return (redir_and_great(redir));
	else if (redir->type == ANDDGREAT)
		return (redir_and_dgreat(redir));
	else
		return (redir_clobber(redir));
}
