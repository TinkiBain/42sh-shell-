/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   traverse_redirect_list.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggwin-go <ggwin-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 19:18:54 by ggwin-go          #+#    #+#             */
/*   Updated: 2019/09/13 22:15:01 by ggwin-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

int		traverse_redirect_list(t_redirect_list *list)
{
	int	res;

	while (list)
	{
		if ((res = redirect(list->io_redirect)) == -1)
			return (res);
		list = list->next;
	}
	return (res);
}
