/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstdelend.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelisan </var/spool/mail/vladimir>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 05:10:38 by gmelisan          #+#    #+#             */
/*   Updated: 2019/07/20 09:05:51 by gmelisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_dlstdelend(t_dlist **alst, void (*del)(void *, size_t))
{
	if (!alst || !*alst)
		return ;
	while ((*alst)->next)
			*alst = (*alst)->next;
	if ((*alst)->prev)
	{
		*alst = (*alst)->prev;
		ft_dlstdelone(&(*alst)->next, del);
		(*alst)->next = NULL;
	}
	else
		ft_dlstdel(alst, del);
}
