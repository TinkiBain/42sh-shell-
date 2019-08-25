/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstaddback.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggwin-go <ggwin-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/16 20:26:44 by gmelisan          #+#    #+#             */
/*   Updated: 2019/08/25 13:50:04 by ggwin-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_dlstaddback(t_dlist **alst, t_dlist *new)
{
	if (!alst || !new)
		return ;
	if (!*alst)
		*alst = new;
	else
	{
		while ((*alst)->next)
			*alst = (*alst)->next;
		new->prev = *alst;
		(*alst)->next = new;
		*alst = (*alst)->next;
	}
}
