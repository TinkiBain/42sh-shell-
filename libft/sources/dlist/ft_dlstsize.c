/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstsize.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelisan </var/spool/mail/vladimir>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/16 20:38:58 by gmelisan          #+#    #+#             */
/*   Updated: 2019/07/16 20:52:23 by gmelisan         ###   ########.fr       */
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
