/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_xstrdup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggwin-go <ggwin-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/24 18:26:03 by ggwin-go          #+#    #+#             */
/*   Updated: 2019/08/24 18:26:04 by ggwin-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "xfuncs.h"

char	*ft_xstrdup(const char *src)
{
	char *p;

	p = NULL;
	if (!src)
		return (NULL);
	p = ft_strdup(src);
	if (!p)
		die();
	return (p);
}
