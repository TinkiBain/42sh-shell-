/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_xstrdup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelisan </var/spool/mail/vladimir>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/17 06:00:29 by gmelisan          #+#    #+#             */
/*   Updated: 2019/08/19 15:20:13 by wtalea           ###   ########.fr       */
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
