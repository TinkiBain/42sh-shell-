/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paste_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wtalea <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/01 19:15:21 by wtalea            #+#    #+#             */
/*   Updated: 2019/08/17 06:58:52 by gmelisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "lib_wtalea.h"
#include "xfuncs.h"

char	*paste_path(char *str1, char *str2)
{
	char	*dst;
	int		len1;
	int		len2;
	char	*cp;

	cp = NULL;
	dst = NULL;
	len1 = ft_strlen(str1);
	len2 = ft_strlen(str2);
	if (len1 && len2)
	{
		if (*(str1 + len1 - 1) != '/')
			dst = ft_strjoin(str1, "/");
		cp = ft_strjoin((dst ? dst : str1), str2);
		if (dst)
			free(dst);
	}
	return (cp);
}
