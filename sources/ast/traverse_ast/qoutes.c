/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   qoutes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jterry <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/12 17:50:20 by jterry            #+#    #+#             */
/*   Updated: 2019/08/12 19:06:30 by jterry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

static int		q_check(char *str)
{
	int			i;
	int			count;

	i = -1;
	count = 0;
	while (str[++i])
	{
		if (str[i] == 39)
		{
			if (count == 0 || count == 2)
				count = 1;
			else if (count == 1)
				count = 2;
		}
	}
	return (count);
}

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
		if (str[i] == 39)
			i++;
		tmp[t_i] = str[i];
		t_i++;
	}
	free(str);
	str = ft_strdup(tmp);
	free(tmp);
	return (str);
}

char			*qoutes(char *str)
{
	int			i;

	i = q_check(str);
	if (i == 1)
	{
		g_errno = 15;
		return (NULL);
	}
	if (i == 0)
		return (NULL);
	str = cleaner(str);
	return (str);
}
