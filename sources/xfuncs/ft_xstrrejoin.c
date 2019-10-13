/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_xstrrejoin.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wtalea <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 16:50:03 by wtalea            #+#    #+#             */
/*   Updated: 2019/10/13 17:23:59 by wtalea           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

char	*ft_xstrrejoin(char const *s1, char const *s2, int numstr_to_free)
{
	char	*p;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	p = ft_strrejoin(s1, s2, numstr_to_free);
	if (!p)
		die();
	return (p);
}
