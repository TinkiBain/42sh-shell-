/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vi_backward_word.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelisan <gmelisan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/15 10:48:27 by gmelisan          #+#    #+#             */
/*   Updated: 2019/08/26 20:43:30 by wtalea           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "actions.h"

static	void	alnum_go(char *str, int *i)
{
	while (*(str + *i) && ft_isalnum(*(str + *i)) && *i)
		--(*i);
}

static	void	space_go(char *str, int *i)
{
	while (*(str + *i) && ft_isspace(*(str + *i)) && *i)
		--(*i);
	if (ft_isprint(*(str + *i)) && !ft_isalnum(*(str + *i)))
		while (*(str + *i) && (ft_isprint(*(str + *i)) &&
					!ft_isalnum(*(str + *i))) && *i)
			--(*i);
	else if (ft_isalnum(*(str + *i)))
		while (*(str + *i) && ft_isalnum(*(str + *i)) && *i)
			--(*i);
}

static	void	signs_go(char *str, int *i)
{
	while (*(str + *i) && (ft_isprint(*(str + *i)) &&
				!ft_isalnum(*(str + *i))) && *i)
		--(*i);
}

static	void	forward_go(char *str, int *cpos)
{
	int		i;

	i = *cpos;
	if (ft_isspace(*(str + i)))
		space_go(str, &i);
	else if (ft_isalnum(*(str + i)))
		alnum_go(str, &i);
	else if (ft_isprint(*(str + i)) && !ft_isalnum(*(str + i)))
		signs_go(str, &i);
	*cpos = i;
}

void		vi_backward_word(t_line *line)
{
	int i;
	int j;

	j = -1;
	while (++j < line->arg)
	{
		i = line->cpos;
		forward_go(line->str->s, &line->cpos);
	}
}
