/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_copy_env.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggwin-go <ggwin-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/08 13:31:09 by ggwin-go          #+#    #+#             */
/*   Updated: 2019/08/09 18:18:49 by ggwin-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**create_copy_env(char **env)
{
	char		**new_env;
	char		**tmp;
	size_t		size;

	tmp = env;
	size = 0;
	while (*(tmp++))
		++size;
	new_env = (char **)ft_xmalloc(sizeof(char *) * (size + 1));
	tmp = new_env;
	while (*env)
	{
		*(tmp++) = ft_strdup(*(env++));
	}
	*tmp = NULL;
	return (new_env);
}
