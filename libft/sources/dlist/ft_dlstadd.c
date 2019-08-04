/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstadd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelisan </var/spool/mail/vladimir>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/16 20:08:20 by gmelisan          #+#    #+#             */
/*   Updated: 2019/07/17 00:33:27 by gmelisan         ###   ########.fr       */
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
