/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vi_replace.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelisan </var/spool/mail/vladimir>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/15 12:25:08 by gmelisan          #+#    #+#             */
/*   Updated: 2019/08/15 12:41:47 by gmelisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "actions.h"

static void	vi_replace_char(t_line *line, char c)
{
	int		i;
	int		j;

	if (ft_isprint(c))
	{
		i = 0;
		j = line->cpos;
		while (i < line->arg && str_get(*line->str, j))
		{
			line->str->s[j] = c;
			i++;
			j++;
		}
		line->cpos = j - 1;
	}
}

void		vi_replace(t_line *line)
{
	int		ret;
	char	c;

	ret = read(STDIN, &c, 1);
	if (ret < 0)
		loginfo("vi_replace(): read error");
	if (c == CTRL_C)
		reset_line(line);
	else
		vi_replace_char(line, c);
}
