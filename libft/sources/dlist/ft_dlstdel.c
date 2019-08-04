/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstdel.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelisan </var/spool/mail/vladimir>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/16 20:06:21 by gmelisan          #+#    #+#             */
/*   Updated: 2019/07/16 23:33:38 by gmelisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_dlstdel(t_dlist **alst, void (*del)(void *, size_t))
{
	t_dlist *temp;

	if (!alst || !*alst)
		return ;
	while ((*alst)->prev)
		*alst = (*alst)->prev;
	while (*alst)
	{
		temp = (*alst)->next;
		ft_dlstdelone(alst, del);
		*alst = temp;
	}
}
