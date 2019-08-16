/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_var.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggwin-go <ggwin-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/17 22:04:36 by ggwin-go          #+#    #+#             */
/*   Updated: 2019/08/15 20:50:01 by ggwin-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"
#include "hash.h"

int		remove_var(const char *av, char ***env)
{
	char		**tmp;
	size_t		len;

	if (!env)
		return (0);
	if (av)
	{
		len = ft_strlen(av);
		tmp = *env;
		while (*tmp && !(ft_strnequ(av, *tmp, len) && *(*tmp + len) == '='))
			++tmp;
		if (*tmp)
		{
			free(*tmp);
			while (*tmp)
			{
				*tmp = *(tmp + 1);
				++tmp;
			}
		}
	}
	return (0);
}
