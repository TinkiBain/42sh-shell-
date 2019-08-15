/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrejoin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggwin-go <ggwin-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 23:55:49 by ggwin-go          #+#    #+#             */
/*   Updated: 2019/08/15 17:11:18 by ggwin-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrejoin(char const *s1, char const *s2, int numstr_to_free)
{
	char	*str;

	str = ft_strjoin(s1, s2);
	if (numstr_to_free & 1)
		ft_memdel((void **)&s1);
	if (numstr_to_free & 2)
		ft_memdel((void **)&s2);
	return (str);
}
