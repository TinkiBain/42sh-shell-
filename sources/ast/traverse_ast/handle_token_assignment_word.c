/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_token_assignment_word.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggwin-go <ggwin-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/05 21:42:57 by ggwin-go          #+#    #+#             */
/*   Updated: 2019/08/17 06:08:45 by gmelisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

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
			*tmp = ft_xstrdup(word);
		}
		else
		{
			add_var((const char *)word, env);
		}
		free(name);
	}
}
