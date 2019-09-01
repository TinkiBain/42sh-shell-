/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace_var.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggwin-go <ggwin-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/15 14:16:54 by ggwin-go          #+#    #+#             */
/*   Updated: 2019/09/01 14:01:55 by ggwin-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

int	replace_var(const char *var, char **env, size_t name_len, int flag)
{
	while (*env && !(ft_strnequ(var, *env, name_len)
			&& *(*env + name_len) == '='))
		++env;
	if (*env)
	{
		free(*env);
		*env = ft_xstrdup(var);
	}
	if (flag)
		ft_memdel((void **)&var);
	return (0);
}
