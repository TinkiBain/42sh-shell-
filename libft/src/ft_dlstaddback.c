/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstaddback.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelisan </var/spool/mail/vladimir>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/16 20:26:44 by gmelisan          #+#    #+#             */
/*   Updated: 2019/07/17 00:31:00 by gmelisan         ###   ########.fr       */
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
