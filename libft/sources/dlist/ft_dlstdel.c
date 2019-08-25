/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstdel.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggwin-go <ggwin-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/16 20:06:21 by gmelisan          #+#    #+#             */
/*   Updated: 2019/08/25 13:50:00 by ggwin-go         ###   ########.fr       */
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
