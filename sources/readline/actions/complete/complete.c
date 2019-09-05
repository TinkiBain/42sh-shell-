/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complete.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelisan <gmelisan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/09 04:39:02 by gmelisan          #+#    #+#             */
/*   Updated: 2019/09/05 23:08:45 by gmelisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "actions.h"

static int	need_complete_command(t_line *line)
{
	int		i;
	char	c;

	i = line->cpos - 1;
	while ((c = str_get(*line->str, i)) && !ft_isspace(c) &&
			c != ';' && c != '/' && c != '(')
		i--;
	if (c == ';' || (c == '(' && str_get(*line->str, i - 1) == '$'))
		return (1);
	if (c == '/')
		return (0);
	while ((c = str_get(*line->str, i)) && ft_isspace(c))
		i--;
	if (c == ';' || c == 0 || (c == '(' && str_get(*line->str, i - 1) == '$'))
		return (1);
	else
		return (0);
}

static int	need_complete_variable(t_line *line)
{
	int		i;
	char	c;

	i = line->cpos - 1;
	while ((c = str_get(*line->str, i)) && !ft_isspace(c)
			&& c != '$' && c != '{' && c != '(')
		i--;
	if ((c == '{' && str_get(*line->str, i - 1) == '$')
		|| c == '$')
		return (1);
	return (0);
}

static int	need_complete_command_argument(t_line *line)
{
	int		i;
	char	c;
	i = line->cpos - 1;
	while ((c = str_get(*line->str, i)) && !ft_isspace(c))
		i--;
	if (!c)
		return (0);
	if (str_get(*line->str, i + 1) == '-')
		return (1);
	return (0);
}

void		complete(t_line *line)
{
	if (need_complete_variable(line))
		complete_variable(line);
	else if (need_complete_command_argument(line))
		complete_command_option(line);
	else if (need_complete_command(line))
		complete_command(line);
	else
		complete_filename(line);
}
