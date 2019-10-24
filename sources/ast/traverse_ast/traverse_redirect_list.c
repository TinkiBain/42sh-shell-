/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   traverse_redirect_list.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jterry <jterry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 19:18:54 by ggwin-go          #+#    #+#             */
/*   Updated: 2019/10/24 21:00:06 by jterry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

int		traverse_redirect_list(t_redirect_list *list, t_pjobs **local)
{
	int	res;

	res = 0;
	redir_set();
	while (list)
	{
		if (list->io_redirect && (res = redirect(list->io_redirect, local)) == -1)
		{
			redir_reset();
			return (res);
		}
		list = list->next;
	}
	return (res);
}
