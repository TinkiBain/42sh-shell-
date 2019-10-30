/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   escaping.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelisan <gmelisan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 17:13:04 by gmelisan          #+#    #+#             */
/*   Updated: 2019/10/30 20:11:27 by gmelisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "actions.h"

int		complete_isspace_check(t_string str, int i)
{
	char	c;
	char	prev;

	c = str_get(str, i);
	prev = str_get(str, i - 1);
	if (ft_isspace(c) && prev == '\\')
		return (0);
	if (ft_isspace(c))
		return (1);
	return (0);
}

void	complete_unescape(t_string *str)
{
	int			i;
	char		c;

	i = -1;
	while ((c = str_get(*str, ++i)))
	{
		if (c == '\\')
			str_remove(str, i, 1);
	}
}

void	complete_escape(t_string *str)
{
	int			i;
	char		c;

	i = 0;
	while ((c = str_get(*str, i)) && i < (int)str->len - 1)
	{
		if (c == ' ')
			str_xinsert(str, i++, "\\", 1);
		i++;
	}
}
