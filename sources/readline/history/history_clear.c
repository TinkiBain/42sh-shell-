/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history_clear.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelisan </var/spool/mail/vladimir>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/21 18:35:48 by gmelisan          #+#    #+#             */
/*   Updated: 2019/08/25 17:25:35 by gmelisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "history.h"

void		del_hist(void *content, size_t size)
{
	if (size || !size)
		str_delete((t_string *)content);
	free(content);
}

void		history_clear(t_history *history)
{
	if (history)
	{
		ft_dlstdel(&history->item, del_hist);
		ft_strdel(&history->path);
		free(history);
	}
}
