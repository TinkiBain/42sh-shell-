/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_back_av.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggwin-go <ggwin-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/05 21:32:34 by ggwin-go          #+#    #+#             */
/*   Updated: 2019/08/05 21:45:21 by ggwin-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

void	push_back_av(char ***av, char *elem)
{
	char	**tmp;
	char	**p;
	size_t	size;
	size_t	i;

	size = 0;
	tmp = *av;
	while (*(tmp++))
		++size;
	p = *av;
	tmp = (char**)ft_xmalloc(sizeof(char*) * (size + 1));
	i = -1;
	while (++i < size)
		*(tmp + i) = *(p + i);
	*(tmp + i++) = elem;
	*(tmp + i) = NULL;
	free(*av);
	*av = tmp;
}
