/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstadd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggwin-go <ggwin-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/16 20:08:20 by gmelisan          #+#    #+#             */
/*   Updated: 2019/08/25 13:50:09 by ggwin-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_dlstadd(t_dlist **alst, t_dlist *new)
{
	if (!alst || !new)
		return ;
	if (!*alst)
		*alst = new;
	else
	{
		while ((*alst)->prev)
			*alst = (*alst)->prev;
		new->next = *alst;
		(*alst)->prev = new;
		*alst = (*alst)->prev;
	}
}
