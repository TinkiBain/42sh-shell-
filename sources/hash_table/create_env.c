/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_env.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wtalea <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/27 16:03:32 by wtalea            #+#    #+#             */
/*   Updated: 2019/07/27 20:25:53 by wtalea           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_env.h"

char	**create_env(char **env)
{
	int		i;
	char	**new_env;

	i = 0;
	new_env = NULL;
	while (*(env + i))
		++i;
	if ((new_env = (char **)malloc(sizeof(char *) * (i + 1))) == NULL)
		die_log("Die on create_env\n");
	i = 0;
	while (*(env + i))
	{
		*(new_env + i) = ft_strdup(*(env + i));
		++i;
	}
	return (new_env);
}
