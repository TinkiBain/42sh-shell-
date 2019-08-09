/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_token_assignment_word.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggwin-go <ggwin-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/05 21:42:57 by ggwin-go          #+#    #+#             */
/*   Updated: 2019/08/09 18:13:40 by ggwin-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

static void	add_var(char *av, char ***env)
{
	char	**new_env;
	char	**tmp;
	size_t	size;

	size = 0;
	tmp = *env;
	while (*(tmp + size))
		++size;
	new_env = (char **)ft_xmalloc(sizeof(char *) * (size + 2));
	ft_bzero(new_env, size + 2);
	tmp = new_env;
	while (size--)
		*(tmp++) = *((*env)++);
	*(tmp++) = ft_strdup(av);
	*tmp = NULL;
	*env = new_env;
}

void	handle_token_assignment_word(char *word, char ***env)
{
	char	*p;
	char	*name;
	char	**tmp;
	size_t	len;

	p = ft_strchr(word, '=');
	if (p)
	{
		name = ft_strndup(word, p - word);
		if (ft_getenv(name, *env))
		{
			len = ft_strlen(name);
			tmp = *env;
			while (!(ft_strnequ(name, *tmp, len) && *(*tmp + len) == '='))
				++tmp;
			free(*tmp);
			*tmp = ft_strdup(word);
		}
		else
		{
			add_var(word, env);
		}
		free(name);
	}
}
