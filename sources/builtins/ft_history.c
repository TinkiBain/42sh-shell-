/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_history.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelisan <gmelisan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/03 16:57:06 by gmelisan          #+#    #+#             */
/*   Updated: 2019/10/03 17:45:54 by gmelisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

int		ft_history(const char **argv)
{
	extern t_history	*g_history;
	t_dlist				*p;
	int					i;

	p = g_history->item;
	ft_dlst2start(&p);
	i = g_history->start_index;
	while (p)
	{
		ft_printf("%5d  %s\n", i, ((t_string *)p->content)->s);
		i++;
		p = p->next;
	}
	if (argv)
		return (0);
	return (0);
}
