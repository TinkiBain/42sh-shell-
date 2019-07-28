/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_lines.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelisan <gmelisan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/21 19:07:22 by gmelisan          #+#    #+#             */
/*   Updated: 2019/02/11 05:18:28 by gmelisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		strarr_del(char ***tab, int n)
{
	int		i;
	char	**t;

	if (!tab || !*tab)
		return ;
	t = *tab;
	i = 0;
	while (i < n)
	{
		ft_strdel(&(t[i]));
		i++;
	}
	free(t);
	*tab = NULL;
}

/*
** Gets array of n lines readed from fd. Returns number of readed lines
** or -1 in case of error.
*/

int				get_lines(int fd, char ***lines, int n)
{
	int	i;
	int	ret;

	if (n <= 0 || fd < 0 || !lines)
		return (0);
	*lines = ft_memalloc(sizeof(**lines) * (n + 1));
	i = 0;
	while (i < n)
	{
		if ((ret = get_next_line(fd, *lines + i)) == 0)
			return (i);
		if (ret == -1)
		{
			strarr_del(lines, i - 1);
			return (-1);
		}
		i++;
	}
	return (i);
}
