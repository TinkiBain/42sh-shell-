/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstnew.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelisan </var/spool/mail/vladimir>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/16 20:06:48 by gmelisan          #+#    #+#             */
/*   Updated: 2019/07/16 20:52:07 by gmelisan         ###   ########.fr       */
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
