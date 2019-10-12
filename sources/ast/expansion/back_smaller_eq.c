/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   back_smaller_eq.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jterry <jterry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/23 18:13:39 by jterry            #+#    #+#             */
/*   Updated: 2019/10/12 18:50:21 by jterry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

static int	favorite(char *s2, int *j, int *i, int *ij)
{
	if (s2[*j] == '*')
	{
		(*j) -= 1;
		return (1);
	}
	if (s2[*j + 1] == '*')
	{
		i[1] = *j;
		*ij -= 1;
		i[0] = *ij;
		return (1);
	}
	if (i[1] == 0 && i[0] == 0)
	{
		*j = ft_strlen(s2) - 1;
		return (2);
	}
	*j = i[1];
	*ij = i[0];
	i[0] = 0;
	return (0);
}

void		ft_while(char *s1, char *s2, int *ij, int *j)
{
	int *i;
	int res;

	i = (int*)malloc(sizeof(int) * 2);
	i[0] = 0;
	i[1] = 1;
	while (ij >= 0 && *j >= 0)
	{
		if (i[0] == 0)
			i[0] = *ij;
		if (s1[*ij] != s2[*j])
		{
			res = favorite(s2, j, i, ij);
			if (res == 1)
				continue ;
			else if (res == 2)
				break ;
		}
		*ij -= 1;
		*j -= 1;
	}
	free(i);
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
	while (i >= 0 && j >= 0)
	{
		if (s1[i] != s2[j] && s2[j] != '*')
			return (-1);
		if (s1[i] == s2[j] || s2[j] == '*')
		{
			ij = i;
			ft_while(s1, s2, &ij, &j);
			while (s2[j] == '*')
				j--;
			if (j == -1)
				return (s2[0] == '*' ? 0 : ij + 1);
			j = ft_strlen(s2) - 1;
		}
		i--;
	}
	return (-1);
}
