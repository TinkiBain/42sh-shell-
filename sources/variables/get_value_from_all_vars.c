/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_value_from_all_vars.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggwin-go <ggwin-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/18 00:11:27 by ggwin-go          #+#    #+#             */
/*   Updated: 2019/08/18 00:22:22 by ggwin-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

char	*get_value_from_all_vars(char *name)
{
	extern char	**environ;
	extern char	**g_var;
	char		*value;

	if ((value = ft_getenv(name, environ)))
		return (value);
	if ((value = ft_getenv(name, g_var)))
		return (value);
	return (NULL);
}
