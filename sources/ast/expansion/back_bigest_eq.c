/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   back_bigest_eq.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jterry <jterry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/22 20:10:18 by jterry            #+#    #+#             */
/*   Updated: 2019/09/22 20:55:05 by jterry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

static int	ft_strnumcmp(const char *str1, const char *str2, size_t n)
{
	size_t i;

	i = 0;
	if (n == 0)
		return (0);
	while (i < n - 1 && str1[i] != '\0' && str2[i] != '\0')
	{
		if (str1[i] != str2[i])
			return (0);
		i++;
	}
	return (i);
}


static char	*find_token(char *s2, int *j)
{
	int		len;
	int		cur_p;
	char	*token;

	*j -= 1;
	cur_p = *j;
	len = 0;
	token = NULL;
	while(*j >= 0 && s2[*j] != '*')
	{
		*j -= 1;
		len++;
	}
	token = malloc(sizeof(char) * (len + 1));
	token[len] = '\0';
	while (cur_p != *j)
		token[--len] = s2[cur_p--];
	return (token);
}

static int	finder_top_word(char *s1, char *s2, int *j, int i)
{
	char *token;
	int ti;
	int c;

	c = 0;
	ti = 0;
	while (*j != 0 && s2[*j - 1] == '*')
		*j -= 1;
	token = find_token(s2, j);
	while (s1[ti] && token)
	{
		if (s1[ti] == *token)
			if ((c = ft_strnumcmp(&s1[ti], token, ft_strlen(token))))
			{
				if (c > i)
					return (-1);
				free(token);
				return(ti);
			}
		ti++;
	}
	if (token)
		free(token);
	return(-1);
}

int			back_bigest_eq(char *s1, char *s2)
{
	int i;
	int j;

	j = ft_strlen(s2) - 1;
	i = ft_strlen(s1) - 1;
	while (i >= 0 && j >= 0)
	{
		if (s1[i] != s2[j])
		{
			if (s2[j] != '*')
				return (-1);
			else if (s2[j] == '*' && j != 0)
				i = finder_top_word(s1, s2, &j, i) - 1;
			else if (s2[j] == '*' && j == 0)
				return (0);
			continue ;
		}
		i--;
		j--;
	}
	while (j >= 0 && s2[j] == '*')
		j--;
	if (i < 0 && j >= 0)
		return (-1);
	return (i + 1);
}
