/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_escapes.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelisan <gmelisan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/20 17:34:04 by gmelisan          #+#    #+#             */
/*   Updated: 2019/08/23 17:09:20 by gmelisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_readline.h"

static int	ft_isdigit_octal(char c)
{
	if (c >= '0' && c <= '7')
		return (1);
	return (0);
}

static t_uchar	ft_atoi_octal(char *str, int *count)
{
	t_uchar	result;
	int		i;

	result = 0;
	i = 0;
	while (ft_isdigit_octal(str[i]))
	{
		result = result * 8 + (str[i] - '0');
		i++;
	}
	*count = i;
	return (result);
}

void	convert_escapes(t_string *str)
{
	int		i;
	char	c;
	t_uchar	n;
	int		count;

	i = -1;
	while ((c = str_get(*str, ++i)))
	{
		if (c == '\\')
			n = ft_atoi_octal(&str->s[i + 1], &count);
		if (n)
		{
			str_remove(str, i, count + 1);
			str_xinsert(str, i, (char *)&n, 1);
		}
		n = 0;
	}
}

