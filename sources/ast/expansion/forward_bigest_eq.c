/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forward_bigest_eq.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jterry <jterry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/02 17:32:08 by jterry            #+#    #+#             */
/*   Updated: 2019/10/07 16:47:31 by jterry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

int			ft_aster(char *s1, char *s2, int i, int j)
{
	int ij;
	int ji;

	ij = ft_strlen(s1) - 1;
	while (s2[j] == '*')
		j++;
	ji = j;
	while (s2[ji] && ij > i)
	{
		ji = j;
		while (ij >= 0 && s1[ij] != s2[j])
			ij--;
		if (ij < 0)
			return (-1);
		i = ij;
		while (s2[ji])
		{
			if (!s1[ij])
			{
				ij = i;
				while (ij >= 0 && s1[ij] != s2[j])
					ij--;
			}
			if (s1[ij] != s2[ji])
			{
				if (s2[ji] == '*')
				{
					ji++;
					j = ji;
					continue ;
				}
				if (s2[ji] && s2[ji - 1] == '*')
				{
					ij++;
					continue ;
				}
				else
				{
					ij = i - 1;
					break ;
				}
			}
			ji++;
			ij++;
		}
	}
	return(ij);
}

int			forward_bigest_eq(char *s1, char *s2)
{
	int i;
	int j;

	i = 0;
	j = 0;
	if (s2[ft_strlen(s2) - 1] == '*')
		return (ft_strlen(s1));
	if (s1[i] != s2[j] && s2[j] != '*')
		return(0);
	while (s2[j])
	{
		if (s1[i] != s2[j])
		{
			if (s2[j] == '*')
				return(ft_aster(s1, s2, i, j));
			return (-1);
		}
		j++;
		i++;
	}
	if (!s2[j])
		return (i);
	return (-1);
}
