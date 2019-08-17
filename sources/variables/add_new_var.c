/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_new_var.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggwin-go <ggwin-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/17 22:04:36 by ggwin-go          #+#    #+#             */
/*   Updated: 2019/08/17 23:29:42 by ggwin-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"
#include "hash.h"

int	add_new_var(const char *av, char ***env)
{
	char	**new_env;
	char	**tmp;
	char	**p;
	size_t	size;

	size = 0;
	p = *env;
	while (*(p++))
		++size;
	new_env = (char **)ft_xmalloc(sizeof(char *) * (size + 2));
	ft_bzero(new_env, sizeof(char *) * (size + 2));
	tmp = new_env;
	p = *env;
	while (*p)
		*(tmp++) = *(p++);
	*(tmp++) = ft_strdup(av);
	*tmp = NULL;
	free(*env);
	*env = new_env;
	fill_g_var_names();
	return (0);
}
