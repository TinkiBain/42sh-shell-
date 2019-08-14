/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   qoutes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jterry <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/12 17:50:20 by jterry            #+#    #+#             */
/*   Updated: 2019/08/14 18:12:05 by jterry           ###   ########.fr       */
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
		if (str[i] == 92)
			i++;
		else if (str[i] == 39)
		{
			if (count == 0 || count == 2)
				count = 1;
			else if (count == 1)
				count = 2;
		}
	}
	return (count);
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
	return (str);
}
