/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_strarray.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggwin-go <ggwin-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 22:10:52 by ggwin-go          #+#    #+#             */
/*   Updated: 2019/02/10 18:23:07 by ggwin-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**ft_rewrite(char **arr, int size)
{
	char	**new;

	new = NULL;
	if (arr && size > 0)
	{
		new = (char **)malloc(sizeof(char *) * (size + 1));
		if (new)
		{
			new[size] = NULL;
			while (size--)
				new[size] = ft_strdup(arr[size]);
		}
	}
	return (new);
}

char		**ft_sort_strarray(char **arr, int rewrite)
{
	char	**new;
	int		i;
	int		j;
	int		size;

	size = 0;
	i = -1;
	while (arr[++i])
		size++;
	if (!rewrite)
	{
		if (!(new = ft_rewrite(arr, size)))
			return (NULL);
	}
	else
		new = arr;
	i = -1;
	while (arr[++i])
	{
		j = i;
		while (++j < size)
			if (ft_strcmp(new[i], new[j]) > 0)
				ft_swap((void **)&new[i], (void **)&new[j]);
	}
	return (new);
}
