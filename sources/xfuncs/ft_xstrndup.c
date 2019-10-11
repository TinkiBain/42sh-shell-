/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_xstrndup.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelisan <gmelisan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 15:16:48 by gmelisan          #+#    #+#             */
/*   Updated: 2019/10/11 20:14:45 by gmelisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "xfuncs.h"

char	*ft_xstrndup(const char *src, int j)
{
	char	*p;

	if (!src)
		return (NULL);
	p = ft_strndup(src, j);
	if (!p)
		die();
	return (p);
}
