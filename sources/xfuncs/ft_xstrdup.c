/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_xstrdup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelisan <gmelisan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/24 18:26:03 by gmelisan          #+#    #+#             */
/*   Updated: 2019/10/13 12:34:45 by gmelisan         ###   ########.fr       */
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
