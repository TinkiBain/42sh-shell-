/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tdq.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jterry <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/14 16:13:52 by jterry            #+#    #+#             */
/*   Updated: 2019/08/14 17:24:06 by jterry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

static char		*cleaner(char *str)
{
	char	*tmp;
	int		i;
	int		t_i;

	i = -1;
	t_i = 0;
	tmp = ft_strnew(ft_strlen(str));
	while (str[++i])
	{
		if (str[i] == 39 || str[i] == 34)
		{
			if (!(str[i - 1] && str[i - 1] == 92))
				i++;
		}
		tmp[t_i] = str[i];
		t_i++;
	}
	free(str);
	str = ft_strdup(tmp);
	free(tmp);
	return (str);
}

char		*tdq(char *str)
{
	char	*tmp;
	int		i;

	i = -1;
	if ((tmp = qoutes(str)) || (tmp = dqoutes(str)))
	{
		while (str[++i])
		{
			if (str[i] == 92)
				i++;
			else if (str[i] == 39)
			{
				i++;
				while (str[i] != 39)
					i++;
			}
			else if (str[i] == 34)
				while (str[i] != 34)
				{
					if (str[i] == '$')
						sokrat(&i, &str);
					else if (str[i] == 92)
						i++;
					i++;
				}
			else if (str[i] == '$')
				sokrat(&i, &str);
		}
		if (*str == '~')
		{
		str = cleaner(str);
		if ((tmp = tilda_check(str)) != NULL)
			str = tmp;
		}
		else 
			str = cleaner(str);
	}
	else
		str = tmp;
	return (str);
}
