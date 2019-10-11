/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_xstrdup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggwin-go <ggwin-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/24 18:26:03 by ggwin-go          #+#    #+#             */
/*   Updated: 2019/10/11 15:18:47 by gmelisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "xfuncs.h"

char	*ft_xstrdup(const char *src)
{
	char	*p;

	if (!src)
		return (NULL);
	p = ft_strdup(src);
	if (!p)
		die();
	return (p);
}
