/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forward_smaller_eq.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jterry <jterry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 20:36:18 by jterry            #+#    #+#             */
/*   Updated: 2019/10/14 16:50:57 by jterry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

static int	ft_while(char *s1, char *s2, int i, int j)
{
	while (s1[i] && s2[j])
	{
		if (s1[i] != s2[j])
		{
			if (s2[j] == '*')
			{
				j++;
				if (!s2[j] && s2[j - 1] == '*')
					return (i);
				continue ;
			}
			if (s2[j - 1] == '*')
			{
				i++;
				continue ;
			}
			return (-1);
		}
		j++;
		i++;
	}
	if (!s2[j])
		return (i);
	return (-1);
}

int			forward_smaller_eq(char *s1, char *s2)
{
	int i;

	i = 0;
	while (s2[i] && s2[i] == '*')
		i++;
	if (!s2[i])
		return (0);
	if (s1[0] != s2[0] && s2[0] != '*')
		return (0);
	else
		return (ft_while(s1, s2, 0, 0));
	return (-1);
}
