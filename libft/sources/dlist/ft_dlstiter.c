/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstiter.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggwin-go <ggwin-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/16 20:36:58 by gmelisan          #+#    #+#             */
/*   Updated: 2019/08/25 13:48:57 by ggwin-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_dlstiter(t_dlist *lst, void (*f)(t_dlist *elem))
{
	while (lst->prev)
		lst = lst->prev;
	while (lst)
	{
		f(lst);
		lst = lst->next;
	}
}
