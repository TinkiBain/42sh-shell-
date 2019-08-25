/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstnew.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggwin-go <ggwin-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/16 20:06:48 by gmelisan          #+#    #+#             */
/*   Updated: 2019/08/25 13:47:18 by ggwin-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_dlist	*ft_dlstnew(void const *content, size_t content_size)
{
	t_dlist *new;

	if (!(new = (t_dlist *)malloc(sizeof(*new))))
		return (NULL);
	ft_bzero(new, sizeof(*new));
	if (!content)
		return (new);
	new->content_size = content_size;
	new->content = (void *)malloc(content_size);
	if (!new->content)
	{
		free(new);
		return (NULL);
	}
	ft_memcpy(new->content, content, content_size);
	return (new);
}
