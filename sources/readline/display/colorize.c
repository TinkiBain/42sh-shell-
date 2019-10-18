/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colorize.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelisan <gmelisan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/26 18:37:50 by gmelisan          #+#    #+#             */
/*   Updated: 2019/10/17 19:39:19 by gmelisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "display.h"
#include "colors.h"

static int	skip_esqseq(t_string *str, int i, int *cpos)
{
	int j;

	j = i;
	j++;
	if (str_get(*str, j) != '[')
		return (j - i - 1);
	j++;
	while (42)
	{
		while (ft_isdigit(str_get(*str, j)))
			j++;
		if (str_get(*str, j) != ';')
			return (j - i);
		j++;
	}
	*cpos += (j - i - 1);
	return (j - i - 1);
}

static int	skip_to_char(t_string *str, int i, char c)
{
	int j;

	j = i;
	j++;
	while (str_get(*str, j) && str_get(*str, j) != c)
		j++;
	return (j - i);
}

static int	colorize_if_need(char c, t_string *str, int i, int *cpos)
{
	int		dif;

	dif = 0;
	if (c == ESC)
		dif = skip_esqseq(str, i, cpos);
	else if ((c == '(' || c == ')') && i == *cpos)
		dif = colorize_paren(str, i, COLOR_BGYELLOW);
	else if (c == '"' || c == '\'')
		dif = skip_to_char(str, i, c);
	else if (c == '-' && ft_isspace(str_get(*str, i - 1)))
		dif = colorize_arg(str, i, COLOR_CYAN, cpos);
	else if (c == '&' || c == '|' || c == ';')
		dif = colorize_cmd_sep(str, i, COLOR_GREEN, cpos);
	else if (c == '$' || c == '{' || c == '}')
		dif = colorize_cmd_sep(str, i, COLOR_PURPLE, cpos);
	else if (c == '>' || c == '<' || c == 0153)
		dif = colorize_cmd_sep(str, i, COLOR_WHITE, cpos);
	else if (c == '\\')
		dif = 1;
	return (dif);
}

void		colorize(t_string *str, int start, int cpos)
{
	int			i;
	char		c;

	i = start - 1;
	cpos += start;
	while ((c = str_get(*str, ++i)))
		i += colorize_if_need(c, str, i, &cpos);
}
