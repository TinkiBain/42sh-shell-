/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_var_value.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggwin-go <ggwin-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/18 00:11:27 by ggwin-go          #+#    #+#             */
/*   Updated: 2019/09/22 18:01:40 by ggwin-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

char	*get_var_value(char *name)
{
	extern char	**g_prefix_vars;
	extern char	**g_var;
	char		*value;
	size_t		len;

	len = ft_strlen(name);
	value = ft_getenv(name, g_prefix_vars, len);
	if (value && *value)
		return (value);
	value = ft_getenv(name, g_var, len);
	if (value && *value)
		return (value);
	return (NULL);
}
