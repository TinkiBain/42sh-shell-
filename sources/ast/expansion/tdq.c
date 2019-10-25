/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tdq.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jterry <jterry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/14 16:13:52 by jterry            #+#    #+#             */
/*   Updated: 2019/10/25 16:39:54 by jterry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

extern t_opt	g_opt;

void			tdq_while(int *i, char **str, t_pjobs **local)
{
	if ((*str)[*i] == '\\')
		(*i) += 1;
	else if ((*str)[*i] == '\'')
		while ((*str)[++(*i)])
		{
			if ((*str)[*i] == '\'')
				break ;
		}
	else if ((*str)[*i] == '\"')
	{
		(*i) += 1;
		while ((*str)[*i] && (*str)[*i] != '\"')
		{
			if ((*str)[*i] == '$' && (*str)[(*i) + 1]
					&& check_spec_symbol((*str)[(*i) + 1]))
				dollar(i, str, local);
			else if ((*str)[*i] == '\\')
				(*i) += 1;
			(*i) += 1;
		}
	}
	else if ((*str)[*i] == '$' && (*str)[(*i) + 1]
			&& check_spec_symbol((*str)[(*i) + 1]))
		dollar(i, str, local);
}

char			*tdq(char *str, t_pjobs **local)
{
	char	*tmp;
	int		i;

	if (!str)
		return (NULL);
	i = 0;
	tmp = str;
	while (str[0] && str[i] != '\0')
	{
		tdq_while(&i, &str, local);
		if (g_opt.arithmetic_error)
			return (str);
		i++;
		i = (ft_strlen(str) < (size_t)i) ? 0 : i;
	}
	if (*str == '~')
	{
		str = cleaner(str);
		if ((tmp = tilda_check(str)) != NULL)
			str = tmp;
	}
	else
		str = cleaner(str);
	return (str);
}
