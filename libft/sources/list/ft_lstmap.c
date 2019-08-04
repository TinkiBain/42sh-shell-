/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelisan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 19:11:36 by gmelisan          #+#    #+#             */
/*   Updated: 2018/11/27 21:13:34 by gmelisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static void	dellink(void *content, size_t size)
{
	if (size)
		free(content);
}

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *first;
	t_list *new;
	t_list *prev;

	prev = NULL;
	first = NULL;
	while (lst)
	{
		new = ft_lstnew(lst->content, lst->content_size);
		if (!new && first)
		{
			ft_lstdel(&first, dellink);
			return (NULL);
		}
		new = f(new);
		if (prev)
			prev->next = new;
		else
			first = new;
		prev = new;
		lst = lst->next;
	}
	return (first);
}
