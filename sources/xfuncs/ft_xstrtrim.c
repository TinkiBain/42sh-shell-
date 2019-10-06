/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_xstrtrim.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelisan <gmelisan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/27 18:55:48 by gmelisan          #+#    #+#             */
/*   Updated: 2019/09/27 18:56:51 by gmelisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "xfuncs.h"

char	*ft_xstrtrim(char const *s)
{
	char	*res;

	if (!s)
		return (NULL);
	res = ft_strtrim(s);
	if (!res)
		die();
	return (res);
}
