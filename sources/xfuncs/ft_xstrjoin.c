/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_xstrjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelisan </var/spool/mail/vladimir>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/17 06:16:08 by gmelisan          #+#    #+#             */
/*   Updated: 2019/08/17 06:18:21 by gmelisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

char	*ft_xstrjoin(char const *s1, char const *s2)
{
	char *p;

	p = ft_strjoin(s1, s2);
	if (!p)
		die();
	return (p);
}
