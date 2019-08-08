/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_copy_environ.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggwin-go <ggwin-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/08 13:31:09 by ggwin-go          #+#    #+#             */
/*   Updated: 2019/08/08 14:03:24 by ggwin-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**create_copy_environ(void)
{
	extern char	**environ;
	char		**env;
	char		**tmp;
	size_t		size;

	tmp = environ;
	size = 0;
	while (*(tmp++))
		++size;
	env = (char **)ft_xmalloc(sizeof(char *) * (size + 1));
	tmp = env;
	while (*environ)
	{
		*(tmp++) = *(environ++);
	}
	*tmp = NULL;
	return (env);
}
