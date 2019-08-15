/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggwin-go <ggwin-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/08 16:41:20 by ggwin-go          #+#    #+#             */
/*   Updated: 2019/08/08 16:51:26 by ggwin-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Return as a result pointer on env value without using malloc.
*/

char	*ft_getenv(const char *name, char **env)
{
	size_t		len;

	if (!name || !env)
		return (NULL);
	len = ft_strlen(name);
	while (*env)
	{
		if (ft_strnequ(name, *env, len) && *(*env + len) == '=')
			break ;
		++env;
	}
	if (*env)
		return (ft_strchr(*env, '=') + 1);
	return (NULL);
}
