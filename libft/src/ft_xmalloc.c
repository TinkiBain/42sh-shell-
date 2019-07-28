/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_xmalloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggwin-go <ggwin-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/28 19:33:25 by ggwin-go          #+#    #+#             */
/*   Updated: 2019/07/28 19:33:26 by ggwin-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_xmalloc(size_t size)
{
	char	*tmp;
	size_t	i;

	if (!(tmp = malloc(size)))
	{
		write(2, "Error malloc\n", 13);
		exit(-1);
	}
	i = -1;
	while (++i < size)
		tmp[i] = '\0';
	return (tmp);
}
