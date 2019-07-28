/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstdelfront.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelisan </var/spool/mail/vladimir>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/16 22:17:18 by gmelisan          #+#    #+#             */
/*   Updated: 2019/07/16 22:30:28 by gmelisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_dlstdelfront(t_dlist **alst, void (*del)(void *, size_t))
{
	if (!alst || !*alst)
		return ;
	while ((*alst)->prev)
			*alst = (*alst)->prev;
	if ((*alst)->next)
	{
		*alst = (*alst)->next;	
		ft_dlstdelone(&(*alst)->prev, del);
		(*alst)->prev = NULL;
	}
	else
		ft_dlstdel(alst, del);
}
