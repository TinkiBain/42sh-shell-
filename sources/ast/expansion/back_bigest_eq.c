/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   back_bigest_eq.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jterry <jterry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/22 20:10:18 by jterry            #+#    #+#             */
/*   Updated: 2019/10/13 12:26:03 by jterry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

static void		ft_while(char *s1, char *s2, int *ij, int *j)
{
	while (s1[*ij])
	{
		if (s1[*ij] != s2[*j])
		{
			if (s2[*j] == '*')
			{
				*j += 1;
				continue ;
			}
			if (s2[*j - 1] == '*')
			{
				*ij += 1;
				continue ;
			}
			*j = 0;
			break ;
		}
		*ij += 1;
		*j += 1;
	}
}

int				back_bigest_eq(char *s1, char *s2)
{
	int i;
	int j;
	int ij;

	i = 0;
	j = 0;
	while (s1[i])
	{
		if (s1[i] == *s2 || *s2 == '*')
		{
			ij = i;
			ft_while(s1, s2, &ij, &j);
			while (s2[j] == '*')
				j++;
			if (!s1[ij] && !s2[j])
				return (i);
			j = 0;
		}
		i++;
	}
	return (-1);
}
