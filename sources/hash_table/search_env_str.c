/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_env_str.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggwin-go <ggwin-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/01 17:29:04 by wtalea            #+#    #+#             */
/*   Updated: 2019/08/08 13:55:00 by ggwin-go         ###   ########.fr       */
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
		char ***env)
{
	int		i;
	int		b;

	i = 0;
	b = 0;
	while (*(*env + b))
	{
		if (ft_memcmp(str, *(*env + b), len))
		{
			++b;
			continue ;
		}
		if (sh_equal_len(*(*env + b)) != len &&
				!ft_memcmp(str, *(*env + b), len))
		{
			++b;
			continue ;
		}
		while (*(*(*env + b) + i) && *(*(*env + b) + i) != '=')
			++i;
		++i;
		if ((*result = ft_strdup((*(*env + b) + i))) == NULL)
			exit(-5);
		return ;
	}
}

char			*search_bucks(char *str, char ***env)
{
	char	**cp;
	char	*result;
	char	*cpstr;
	int		len;

	result = NULL;
	cpstr = NULL;
	cp = *env;
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
				(len ? len : ft_strlen(str)), env);
	if (cpstr)
		free(cpstr);
	return (result);
}
