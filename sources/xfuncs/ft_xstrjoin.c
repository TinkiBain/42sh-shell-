/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_xstrjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelisan <gmelisan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/24 18:26:23 by gmelisan          #+#    #+#             */
/*   Updated: 2019/10/13 12:34:57 by gmelisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

char	*ft_xstrjoin(char const *s1, char const *s2)
{
	char *p;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	p = ft_strjoin(s1, s2);
	if (!p)
		die();
	return (p);
}
