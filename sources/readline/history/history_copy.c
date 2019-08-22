/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history_copy.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelisan </var/spool/mail/vladimir>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/21 18:37:24 by gmelisan          #+#    #+#             */
/*   Updated: 2019/08/21 18:37:35 by gmelisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "history.h"

t_history	*history_copy(t_history *history)
{
	t_history	*newhist;
	t_string	str;

	newhist = ft_xmemalloc(sizeof(*newhist));
	newhist->path = ft_xstrdup(history->path);
	newhist->max_size = history->max_size;
	if (history->size == 0)
		return (newhist);
	while (history->item->prev)
		history->item = history->item->prev;
	while (history->item->next)
	{
		str = str_xduplicate(*((t_string *)history->item->content));
		history_push(newhist, str);
		history->item = history->item->next;
	}
	str = str_xduplicate(*((t_string *)history->item->content));
	history_push(newhist, str);
	return (newhist);
}
