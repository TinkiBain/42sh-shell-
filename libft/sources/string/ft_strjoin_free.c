/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_free.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggwin-go <ggwin-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 23:55:49 by ggwin-go          #+#    #+#             */
/*   Updated: 2019/02/10 18:24:10 by ggwin-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin_free(char const *s1, char const *s2, int numstr_to_free)
{
	char	*str;

	str = ft_strjoin(s1, s2);
	if (numstr_to_free == 1)
		free((void *)s1);
	else if (numstr_to_free == 2)
		free((void *)s2);
	else if (numstr_to_free == 3)
	{
		free((void *)s1);
		free((void *)s2);
	}
	return (str);
}
