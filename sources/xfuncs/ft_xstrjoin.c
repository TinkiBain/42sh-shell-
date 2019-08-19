/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_xstrjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelisan </var/spool/mail/vladimir>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/17 06:16:08 by gmelisan          #+#    #+#             */
/*   Updated: 2019/08/19 15:21:38 by wtalea           ###   ########.fr       */
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
