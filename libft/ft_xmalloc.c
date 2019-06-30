/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_xmalloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwisoky <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 22:25:41 by dwisoky           #+#    #+#             */
/*   Updated: 2019/04/23 04:25:02 by dwisoky          ###   ########.fr       */
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
