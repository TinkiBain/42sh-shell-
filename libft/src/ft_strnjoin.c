/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelisan <gmelisan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 11:39:41 by gmelisan          #+#    #+#             */
/*   Updated: 2019/02/18 12:14:20 by gmelisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_vstrnjoin(int n, va_list varg)
{
	char	*str;
	char	*ret;
	int		len;
	int		oldlen;

	oldlen = 0;
	ret = NULL;
	while (--n >= 0)
	{
		str = va_arg(varg, char *);
		len = ft_strlen(str);
		ft_realloc((void **)&ret, oldlen, oldlen + len + 1);
		ft_memcpy(ret + oldlen, str, len);
		oldlen += len;
	}
	return (ret);
}

char		*ft_strnjoin(int n, ...)
{
	va_list	varg;
	char	*ret;

	va_start(varg, n);
	ret = (n > 0) ? ft_vstrnjoin(n, varg) : NULL;
	va_end(varg);
	return (ret);
}
