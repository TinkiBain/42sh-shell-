/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colorize_functions.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelisan <gmelisan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 15:40:52 by gmelisan          #+#    #+#             */
/*   Updated: 2019/10/18 17:29:44 by gmelisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "display.h"
#include "colors.h"

int		colorize_arg(t_string *str, int i, char *color, int *cpos)
{
	int		j;
	char	c;

	j = i;
	str_xinsert(str, j, color, ft_strlen(color));
	j += ft_strlen(color);
	while ((c = str_get(*str, j)) &&
			!ft_isspace(c) &&
			ft_strchr(")]};&|<>", c) == NULL)
	{
		*cpos -= 1;
		j += 1;
	}
	str_xinsert(str, j, COLOR_EOC, ft_strlen(COLOR_EOC));
	j += ft_strlen(COLOR_EOC) - 1;
	loginfo("colorize_arg() -> %d", j - i);
	*cpos += (j - i + 1);
	return (j - i);
}

int		colorize_cmd_sep(t_string *str, int i, char *color, int *cpos)
{
	int		j;

	j = i;
	if (!ft_isalpha(str_get(*str, j)))
	{
		str_xinsert(str, j, color, ft_strlen(color));
		j += ft_strlen(color);
		j += 1;
		str_xinsert(str, j, COLOR_EOC, ft_strlen(COLOR_EOC));
		j += ft_strlen(COLOR_EOC) - 1;
	}
	else
		*cpos -= colorize_alpha(str, &j);
	*cpos += (j - i);
	return (j - i);
}

static int	find_matching_paren(t_string *str, int i)
{
	char	c;
	int		skip;

	skip = 0;
	if ((c = str_get(*str, i)) == '(')
		while ((c = str_get(*str, ++i)))
		{
			if (c == '(')
				skip++;
			else if (c == ')' && skip)
				skip--;
			else if (c == ')')
				break ;
		}
	else if (c == ')')
		while ((c = str_get(*str, --i)))
		{
			if (c == ')')
				skip++;
			else if (c == '(' && skip)
				skip--;
			else if (c == '(')
				break ;
		}
	return (i);
}

int		colorize_paren(t_string *str, int i, char *color)
{
	int		j;
	int		k;
	int		dir;
	
	dir = (str_get(*str, i) == '(' ? 1 : -1);
	j = find_matching_paren(str, i);
	if (str_get(*str, j))
	{
		k = j;
		str_xinsert(str, j, color, ft_strlen(color));
		j += ft_strlen(color);
		j += 1;
		str_xinsert(str, j, COLOR_EOC, ft_strlen(COLOR_EOC));
		j += ft_strlen(COLOR_EOC) - 1;
		return (dir < 0 ? j - k : 0);
	}
	return (0);
}
