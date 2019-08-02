/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_env_str.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wtalea <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/01 17:29:04 by wtalea            #+#    #+#             */
/*   Updated: 2019/08/01 17:32:42 by wtalea           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_env.h"

int				sh_equal_len(char *str)
{
	int		i;

	i = 0;
	while (*(str + i) && (*(str + i) != '='))
		++i;
	return (i);
}

void			search_bucks_dop(char *str, char **result, int len,
		char ***g_env)
{
	int		i;
	int		b;

	i = 0;
	b = 0;
	while (*(*g_env + b))
	{
		if (ft_memcmp(str, *(*g_env + b), len))
		{
			++b;
			continue ;
		}
		if (sh_equal_len(*(*g_env + b)) != len &&
				!ft_memcmp(str, *(*g_env + b), len))
		{
			++b;
			continue ;
		}
		while (*(*(*g_env + b) + i) && *(*(*g_env + b) + i) != '=')
			++i;
		++i;
		if ((*result = ft_strdup((*(*g_env + b) + i))) == NULL)
			exit(-5);
		return ;
	}
}

char			*search_bucks(char *str, char ***g_env)
{
	char	**cp;
	char	*result;
	char	*cpstr;
	int		len;

	result = NULL;
	cpstr = NULL;
	cp = *g_env;
	len = (ft_strchr(str, ' ') == NULL) ? 0 : (ft_strchr(str, ' ') - str - 1);
	if (len)
	{
		if ((cpstr = malloc(len + 1)) == NULL)
			exit(-5);
		ft_memcpy(cpstr, str, len);
		*(cpstr + len) = '\0';
	}
	if (str)
		search_bucks_dop((len ? cpstr : str), &result,
				(len ? len : ft_strlen(str)), g_env);
	if (cpstr)
		free(cpstr);
	return (result);
}
