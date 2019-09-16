/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_xstrsplit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelisan <gmelisan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 12:47:12 by gmelisan          #+#    #+#             */
/*   Updated: 2019/09/16 12:51:26 by gmelisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "xfuncs.h"

char	**ft_xstrsplit(char const *s, char c)
{
	char	**p;

	if (!s)
		return (NULL);
	p = ft_strsplit(s, c);
	if (!p)
		die();
	return (p);
}
