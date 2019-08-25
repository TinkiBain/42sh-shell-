/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstdelend.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggwin-go <ggwin-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 05:10:38 by gmelisan          #+#    #+#             */
/*   Updated: 2019/08/25 13:49:07 by ggwin-go         ###   ########.fr       */
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
