/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_var_name.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggwin-go <ggwin-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/16 20:02:38 by ggwin-go          #+#    #+#             */
/*   Updated: 2019/08/16 21:44:09 by ggwin-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*get_var_name(const char *var, size_t *name_len)
{
	char	*p;
	size_t	size;

	if ((p = ft_strchr(var, '=')))
	{
		size = p - var;
		if (name_len)
			*name_len = size;
		return (ft_strndup(var, size));
	}
	return (NULL);
}
