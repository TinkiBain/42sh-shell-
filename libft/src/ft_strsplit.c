/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelisan <gmelisan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/25 23:15:49 by gmelisan          #+#    #+#             */
/*   Updated: 2019/02/11 05:43:41 by gmelisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Counts words to get size for main array
*/

static int	count_size(char const *s, char c)
{
	int size;
	int i;

	size = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] == '\0')
			break ;
		while (s[i] != c && s[i] != '\0')
			i++;
		size++;
	}
	return (size);
}

/*
** Gets index of 1st letter of word and returns
** length of this word, using 'c' as separator.
*/

static int	get_word_len(char const *s, char c, int i)
{
	int len;

	len = 0;
	while (s[i] != c && s[i] != '\0')
	{
		len++;
		i++;
	}
	return (len);
}

/*
** Gets index of 1st letter of word and returns
** index of 1st letter of next word, or index of '\0'.
*/

static int	get_next_word(char const *s, char c, int i)
{
	while (s[i] != c && s[i] != '\0')
		i++;
	while (s[i] == c)
		i++;
	return (i);
}

static int	copy_words(char const *s, char c, char **res)
{
	int i;
	int j;
	int len;

	i = 0;
	j = 0;
	while (s[i] == c)
		i++;
	if (s[i] == '\0')
		res[j] = 0;
	while (s[i])
	{
		len = get_word_len(s, c, i);
		res[j] = ft_strsub(s, i, len);
		if (!res[j])
		{
			i = 0;
			while (i < j)
				free(res[i++]);
			return (0);
		}
		j++;
		i = get_next_word(s, c, i);
	}
	return (1);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**res;

	res = (char **)ft_memalloc(sizeof(*res) * (count_size(s, c) + 1));
	if (!res)
		return (NULL);
	if (!copy_words(s, c, res))
	{
		free(res);
		return (NULL);
	}
	return (res);
}
