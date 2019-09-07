/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_num.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wtalea <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 18:13:34 by wtalea            #+#    #+#             */
/*   Updated: 2019/09/07 18:24:09 by wtalea           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_find_num(char *str)
{
	if (str)
	{
		while (*str && ft_isspace(*str))
			++str;
		while (*str && ft_isalnum(*str))
			++str;
		if (!*str)
			return (0);
	}
	return (1);
}
