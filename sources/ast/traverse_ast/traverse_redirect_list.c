/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   traverse_redirect_list.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggwin-go <ggwin-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 19:18:54 by ggwin-go          #+#    #+#             */
/*   Updated: 2019/09/10 19:27:52 by ggwin-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

void		traverse_redirect_list(t_redirect_list *list)
{
	while (list)
	{
		if (redirect(list->io_redirect))
			return ;
		list = list->next;
	}
}
