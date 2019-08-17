/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_xstrdup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelisan </var/spool/mail/vladimir>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/17 06:00:29 by gmelisan          #+#    #+#             */
/*   Updated: 2019/08/17 06:02:33 by gmelisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "xfuncs.h"

char	*ft_xstrdup(const char *src)
{
	char *p;

	p = ft_strdup(src);
	if (!p)
		die();
	return (p);
}
