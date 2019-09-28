/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forward_smaller_eq.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jterry <jterry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 20:36:18 by jterry            #+#    #+#             */
/*   Updated: 2019/09/28 20:01:55 by jterry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

int			forward_smaller_eq(char *s1, char *s2)
{
	int i;
	int j;

	i = 0;
	j = 0;
	if (s1[i] != s2[j] && s2[j] != '*')
		return(ft_strlen(s1));
	else
	{
		while (s2[j])
		{
			if (s1[i] != s2[j] && s2[j] != '*')
				return(-1);
			if (s2[j] == '*')
			{
				j++;
				continue ;
			}
			if (s1[i] != s2[j] && s2[j] && s2[j - 1] == '*')
			{
				i++;
				continue ;
			}
			j++;
			i++;
		}
		if (!s2[j])
			return (i);
	}
	return (-1);
}
