/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complete.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelisan </var/spool/mail/vladimir>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/09 04:39:02 by gmelisan          #+#    #+#             */
/*   Updated: 2019/08/13 07:50:25 by gmelisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "actions.h"

static int	need_complete_command(t_line *line)
{
	int		i;
	char	c;

	i = line->cpos - 1;
	while ((c = str_get(*line->str, i)) && !ft_isspace(c) && c != ';')
		i--;
	if (c == ';')
		return (1);
	while ((c = str_get(*line->str, i)) && ft_isspace(c))
		i--;
	if (c == ';' || c == 0)
		return (1);
	else
		return (0);
}

static int	need_complete_variable(t_line *line)
{
	if (line)
		return (0);
	return (0);
}

void		complete(t_line *line)
{
	if (line->cpos == 0)
		return ;
	if (need_complete_command(line))
		complete_command(line);
	else if (need_complete_variable(line))
		complete_variable(line);
	else
		complete_filename(line);
}
