/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transpose_words.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wtalea <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/05 14:04:29 by wtalea            #+#    #+#             */
/*   Updated: 2019/08/09 17:51:53 by gmelisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "actions.h"

static	void	tw_check_null(char *str, int cpos, t_line *line)
{
	int		len;

	len = 0;
	if (!cpos)
		return ;
	--cpos;
	while (*(str + cpos) && ft_isalnum(*(str + cpos)) && cpos >= 0)
	{
		--cpos;
		++len;
	}
	while (*(str + cpos) && ft_isspace(*(str + cpos)) && cpos >= 0)
	{
		--cpos;
		++len;
	}
	if (cpos < 0)
		return ;
	while (*(str + cpos) && ft_isalnum(*(str + cpos)) && cpos >= 0)
	{
		--cpos;
		++len;
	}
	tw_trans_words((str + ++cpos), str, len, line);
}

static	void	tw_check_char(char *str, int cpos, t_line *line)
{
	int		len;

	len = 0;
	while (*(str + cpos) && ft_isalnum(*(str + cpos)))
		++cpos;
	--cpos;
	while (*(str + cpos) && ft_isalnum(*(str + cpos)))
	{
		++len;
		--cpos;
	}
	while (*(str + cpos) && ft_isspace(*(str + cpos)) && cpos >= 0)
	{
		++len;
		--cpos;
	}
	if (cpos < 0)
		return ;
	while (*(str + cpos) && ft_isalnum(*(str + cpos)) && cpos >= 0)
	{
		++len;
		--cpos;
	}
	tw_trans_words((str + ++cpos), str, len, line);
}

static	void	tw_space_centre(char *str, int cpos, t_line *line)
{
	int		len;

	len = 0;
	while (*(str + cpos) && ft_isalnum(*(str + cpos)))
		++cpos;
	--cpos;
	while (*(str + cpos) && ft_isalnum(*(str + cpos)) && cpos >= 0)
	{
		--cpos;
		++len;
	}
	while (*(str + cpos) && ft_isspace(*(str + cpos)) && cpos >= 0)
	{
		--cpos;
		++len;
	}
	if (cpos < 0)
		return ;
	while (*(str + cpos) && ft_isalnum(*(str + cpos)) && cpos >= 0)
	{
		--cpos;
		++len;
	}
	tw_trans_words((str + ++cpos), str, len, line);
}

static	void	tw_chech_space(char *str, int cpos, t_line *line)
{
	int		i;

	i = cpos;
	while (*(str + cpos) && ft_isspace(*(str + i)) && i >= 0)
		--i;
	if (i < 0)
		return ;
	while (*(str + cpos) && ft_isspace(*(str + cpos)))
		++cpos;
	if (!*(str + cpos))
	{
		while (*(str + i) && ft_isalnum(*(str + i)) && i >= 0)
			--i;
		while (*(str + i) && ft_isspace(*(str + i)) && cpos >= 0)
			--i;
		if (!(cpos-- * 0) && i < 0)
			return ;
		while (*(str + i) && ft_isalnum(*(str + i)) && i >= 0)
			--i;
		while (*(str + cpos) && ft_isspace(*(str + cpos)) && cpos >= 0)
			--cpos;
		tw_trans_words((str + ++i), str, cpos, line);
	}
	else
		tw_space_centre(str, cpos, line);
}

void			transpose_words(t_line *line)
{
	if (line)
	{
		if (ft_isalnum(*(line->str->s + line->cpos)))
			tw_check_char(line->str->s, line->cpos, line);
		else if (ft_isspace(*(line->str->s + line->cpos)))
			tw_chech_space(line->str->s, line->cpos, line);
		else if (!*(line->str->s + line->cpos))
			tw_check_null(line->str->s, line->cpos, line);
	}
}
