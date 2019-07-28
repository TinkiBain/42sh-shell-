/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strarrdel.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemmeric <kemmeric@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 16:01:22 by kemmeric          #+#    #+#             */
/*   Updated: 2019/02/11 05:49:21 by gmelisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Clears array of strings delimited by 0.
*/

#include "libft.h"

void	ft_strarrdel(char ***tab)
{
	size_t	i;
	char	**t;

	if (!tab || !*tab)
		return ;
	t = *tab;
	i = 0;
	while (t[i])
	{
		ft_strdel(&(t[i]));
		i++;
	}
	free(t);
	*tab = NULL;
}
