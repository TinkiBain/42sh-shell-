/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstsize.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggwin-go <ggwin-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/16 20:38:58 by gmelisan          #+#    #+#             */
/*   Updated: 2019/08/25 13:48:48 by ggwin-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_dlstsize(t_dlist *lst)
{
	t_dlist	*il;
	size_t	size;

	il = lst;
	size = 0;
	if (!il)
		return (size);
	while (il)
	{
		il = il->prev;
		size++;
	}
	il = lst;
	while (il)
	{
		il = il->next;
		size++;
	}
	size++;
	return (size);
}
