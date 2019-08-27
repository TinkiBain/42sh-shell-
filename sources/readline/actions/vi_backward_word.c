/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vi_backward_word.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelisan <gmelisan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/15 10:48:27 by gmelisan          #+#    #+#             */
/*   Updated: 2019/08/27 15:32:52 by wtalea           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "actions.h"

static	void	space_go(char *str, int *i)
{
	if (*i < 0)
		*i = 0;
	while (*i && *(str + *i) && ft_isspace(*(str + *i)))
		--(*i);
	if ((*i) && (ft_isprint(*(str + (*i))) &&
			!ft_isalnum(*(str + (*i))) && !ft_isspace(*(str + (*i)))))
		while (((*i - 1) >= 0) && *(str + (*i - 1)) &&
				(ft_isprint(*(str + (*i - 1))) &&
			!ft_isalnum(*(str + (*i - 1)))) && !ft_isspace(*(str + (*i - 1))))
			--(*i);
	else if ((*i) && ft_isalnum(*(str + (*i))))
		while (((*i - 1) >= 0) && *(str + (*i - 1)) &&
				ft_isalnum(*(str + (*i - 1))))
			--(*i);
}

static	void	alnum_go(char *str, int *i)
{
	if (((*i - 1) >= 0) && ft_isspace(*(str + (*i - 1))))
	{
		--(*i);
		space_go(str, i);
	}
	else if (((*i - 1) >= 0) && (ft_isprint(*(str + (*i - 1))) &&
			!ft_isalnum(*(str + (*i - 1))) && !ft_isspace(*(str + (*i - 1)))))
		while (((*i - 1) >= 0) && *(str + (*i - 1)) &&
				(ft_isprint(*(str + (*i - 1))) &&
			!ft_isalnum(*(str + (*i - 1))) && !ft_isspace(*(str + (*i - 1)))))
			--(*i);
	else if (((*i - 1) >= 0) && ft_isalnum(*(str + (*i - 1))))
		while (((*i - 1) >= 0) && *(str + (*i - 1)) &&
				ft_isalnum(*(str + (*i - 1))))
			--(*i);
}

static	void	signs_go(char *str, int *i)
{
	if (((*i - 1) >= 0) && ft_isspace(*(str + (*i - 1))))
	{
		--(*i);
		space_go(str, i);
	}
	else if (((*i - 1) >= 0) && ft_isalnum(*(str + (*i - 1))))
		while (((*i - 1) >= 0) && *(str + (*i - 1)) &&
				ft_isalnum(*(str + (*i - 1))))
			--(*i);
	else if (((*i - 1) >= 0) && ft_isprint(*(str + (*i - 1))) &&
		!ft_isalnum(*(str + (*i - 1))) && !ft_isspace(*(str + (*i - 1))))
		while (((*i - 1) >= 0) && *(str + (*i - 1)) &&
				(ft_isprint(*(str + (*i - 1))) &&
			!ft_isalnum(*(str + (*i - 1))) && !ft_isspace(*(str + (*i - 1)))))
			--(*i);
}

static	void	forward_go(char *str, int *cpos)
{
	int		i;

	i = *cpos;
	if (i)
	{
		if (ft_isspace(*(str + i)))
			space_go(str, &i);
		else if (ft_isalnum(*(str + i)))
			alnum_go(str, &i);
		else if (ft_isprint(*(str + i)) && !ft_isalnum(*(str + i)) &&
				!ft_isspace(*(str + i)))
			signs_go(str, &i);
		*cpos = i;
	}
}

void			vi_backward_word(t_line *line)
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
