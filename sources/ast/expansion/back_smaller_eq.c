/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   back_smaller_eq.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jterry <jterry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/23 18:13:39 by jterry            #+#    #+#             */
/*   Updated: 2019/09/23 20:48:19 by jterry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

void		ft_while(char *s1, char *s2, int *ij, int *j)
{
	while (ij >= 0 && *j >= 0)
	{
		if (s1[*ij] != s2[*j])
		{
			if (s2[*j] == '*')
			{
				(*j) -= 1;
				continue ;
			}
			if (s2[*j + 1] == '*')
			{
				*ij -= 1;
				continue ;
			}
			*j = ft_strlen(s2) - 1;
			break ;
		}
		*ij -= 1;
		*j -= 1;
	}
}

int			back_smaller_eq(char *s1, char *s2)
{
	int i;
	int j;
	int ij;

	i = ft_strlen(s1) - 1;
	j = ft_strlen(s2) - 1;
	if (j == 0 && s2[j] == '*')
		return (0);
	while (i != 0 && j != 0)
	{
		if (s1[i] == s2[j] || s2[j] == '*')
		{
			ij = i;
			ft_while(s1, s2, &ij, &j);
			while(s2[j] == '*')
				j--;
			if (j == -1)
				return (s2[0] == '*' ? 0 : ij + 1);
			j = ft_strlen(s2) - 1;
		}
		i--;
	}
	return (-1);
}
