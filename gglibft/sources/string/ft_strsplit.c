/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggwin-go <ggwin-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 23:50:52 by ggwin-go          #+#    #+#             */
/*   Updated: 2019/02/10 18:25:38 by ggwin-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_itlines(char const *s, char c)
{
	size_t	count;

	count = 0;
	if (!s)
		return (0);
	while (*s != '\0' && *s == c)
		s++;
	if (*s != '\0' && *s != c)
	{
		count++;
		s++;
	}
	while (*s != '\0')
	{
		if (*s == c && (ft_strlen_or_chr(s + 1, c) > 0))
			count++;
		s++;
	}
	return (count);
}

static int		ft_error(char ***arr)
{
	ft_free_char_arr(arr);
	return (0);
}

static int		ft_fillarr(char **arr, char const *s, char c)
{
	size_t	i;
	size_t	count;

	count = ft_itlines(s, c);
	while (*s != '\0' && count)
	{
		if (*s != c && !*arr && !(i = 0))
			if (!(*arr = ft_strnew(ft_strlen_or_chr(s, c) + 1)))
				return (ft_error(&arr));
		if (*arr && *s == c)
		{
			(*arr)[i] = '\0';
			if (ft_strlen_or_chr(s + 1, c) > 0)
			{
				count--;
				arr++;
			}
		}
		else if (*arr)
			(*arr)[i++] = *s;
		s++;
	}
	(*arr)[i] = '\0';
	return (1);
}

char			**ft_strsplit(char const *s, char c)
{
	size_t	count;
	size_t	i;
	char	**arr;

	count = ft_itlines(s, c);
	if (!s || !(arr = (char **)malloc(sizeof(char *) * (count + 1))))
		return (NULL);
	i = 0;
	while (i <= count)
		arr[i++] = NULL;
	while (*s != '\0' && *s == c)
		s++;
	if (count && ft_fillarr(arr, s, c) == 0)
		return (NULL);
	return (arr);
}
