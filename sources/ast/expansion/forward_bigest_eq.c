/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forward_bigest_eq.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jterry <jterry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/02 17:32:08 by jterry            #+#    #+#             */
/*   Updated: 2019/10/14 18:06:56 by jterry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

static int	no_eq(char *s2, int *ij, int *j, int *i)
{
	if (s2[ij[1]] == '*')
	{
		if (s2[ij[1]] == '*' && s2[ij[1] + 1] == '\0')
			return (3);
		ij[1]++;
		*j = ij[1];
		return (1);
	}
	if (s2[ij[1]] && s2[ij[1] - 1] == '*')
	{
		ij[0]++;
		return (1);
	}
	else
	{
		ij[0] = *i - 1;
		return (2);
	}
	return (0);
}

static int	checker(char *s1, char *s2, int *i, int *j)
{
	int res;

	res = 0;
	if (!s1[i[0]])
	{
		i[0] = j[0];
		while (i >= 0 && s1[i[0]] != s2[j[1]])
			i[0]--;
	}
	if (s1[i[0]] != s2[i[1]])
	{
		res = no_eq(s2, i, &j[1], &j[0]);
		if (res == 1)
			return (1);
		else if (res == 2)
			return (2);
		else if (res == 3)
			return (3);
	}
	return (0);
}

static int	main_loop(char *s1, char *s2, int *i, int *j)
{
	int res;

	i[1] = j[1];
	while (i[0] >= 0 && s1[i[0]] != s2[j[1]])
		i[0]--;
	if (i[0] < 0)
		return (-1);
	j[0] = i[0];
	while (s2[i[1]])
	{
		res = checker(s1, s2, i, j);
		if (res == 1)
			continue ;
		else if (res == 2)
			break ;
		else if (res == 3)
			return (-2);
		i[1]++;
		i[0]++;
	}
	return (0);
}

int			ft_aster(char *s1, char *s2, int ij, int ji)
{
	int *i;
	int *j;
	int res;

	i = (int *)malloc(sizeof(int) * 2);
	j = (int *)malloc(sizeof(int) * 2);
	j[0] = ij;
	j[1] = ji;
	i[0] = ft_strlen(s1) - 1;
	while (s2[j[1]] == '*')
		j[1]++;
	i[1] = j[1];
	while (s2[i[1]] && i[0] > j[0])
		if ((res = main_loop(s1, s2, i, j)) < 0)
		{
			free(i);
			if (res == -2)
				return (ft_strlen(s1));
			return (-1);
		}
	res = i[0];
	free(i);
	return (res);
}

int			forward_bigest_eq(char *s1, char *s2)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (s2[i] == '*')
		i++;
	if (s2[i] == '\0')
		return (ft_strlen(s2));
	if (s1[i] != s2[j] && s2[j] != '*')
		return (0);
	while (s2[j])
	{
		if (s1[i] != s2[j])
		{
			if (s2[j] == '*')
				return (ft_aster(s1, s2, i, j));
			return (-1);
		}
		j++;
		i++;
	}
	if (!s2[j])
		return (i);
	return (-1);
}
