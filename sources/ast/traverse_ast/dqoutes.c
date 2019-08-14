/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dqoutes.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jterry <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/14 16:35:10 by jterry            #+#    #+#             */
/*   Updated: 2019/08/14 18:12:10 by jterry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

static int		dq_check(char *str)
{
	int		i;
	char	count;	

	i = -1;
	count = 0;
	while (str[++i])
	{
		if (str[i] == 92)
			i++;
		else if (str[i] == 34)
		{
			if (count == 0 || count == 2)
				count = 1;
			else if (count == 1)
				count = 2;
		}
	}
	return (count);
}

char			*dqoutes(char *str)
{
	int		i;

	i = dq_check(str);
	if (i == 1)
	{
		g_errno = 16;
		return (NULL);
	}
	return (str);
}
