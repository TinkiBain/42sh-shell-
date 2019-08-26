/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colorize.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelisan <gmelisan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/26 18:37:50 by gmelisan          #+#    #+#             */
/*   Updated: 2019/08/27 00:35:02 by gmelisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "display.h"
#include "colors.h"

static int	skip_esqseq(t_string *str, int i)
{
	i++;
	if (str_get(*str, i) != '[')
		return (i - 1);
	i++;
	while (42)
	{
		while (ft_isdigit(str_get(*str, i)))
			i++;
		if (str_get(*str, i) != ';')
			return (i);
		i++;
	}
	return (i - 1);
}

static int	skip_to_char(t_string *str, int i, char c)
{
	i++;
	while (str_get(*str, i) && str_get(*str, i) != c)
		i++;
	return (i);
}

static void	colorize_arg(t_string *str, int *i, char *color)
{
	char	c;

	str_xinsert(str, *i, color, ft_strlen(color));
	*i += ft_strlen(color);
	while ((c = str_get(*str, *i)) && !ft_isspace(c))
		*i += 1;
	str_xinsert(str, *i, COLOR_EOC, ft_strlen(COLOR_EOC));
	*i += ft_strlen(COLOR_EOC) - 1;
}

static void	colorize_cmd_sep(t_string *str, int *i, char *color)
{
	str_xinsert(str, *i, color, ft_strlen(color));
	*i += ft_strlen(color);
	*i += 1;
	str_xinsert(str, *i, COLOR_EOC, ft_strlen(COLOR_EOC));
	*i += ft_strlen(COLOR_EOC) - 1;
}

void		colorize(t_string *str, int start)
{
	int			i;
	char		c;

	i = start - 1;
	while ((c = str_get(*str, ++i)))
	{
		if (c == ESC)
			i = skip_esqseq(str, i);
		else if (c == '"' || c == '\'')
			i = skip_to_char(str, i, c);
		else if (c == '-' && ft_isspace(str_get(*str, i - 1)))
			colorize_arg(str, &i, COLOR_GREY);
		else if (c == '&' || c == '|' || c == ';')
			colorize_cmd_sep(str, &i, COLOR_GREEN);
		else if (c == '>' || c == '<')
			colorize_cmd_sep(str, &i, COLOR_WHITE);
		else if (c == '\\')
			++i;
	}
}
