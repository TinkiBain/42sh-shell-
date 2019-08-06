/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transpose_words.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wtalea <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/05 14:04:29 by wtalea            #+#    #+#             */
/*   Updated: 2019/08/05 16:15:00 by wtalea           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "actions.h"

static	void	tw_trans_words(char *str, char *add, int len, t_line *line)
{
	int		len1;
	int		lensp;
	int		len2;
	char	*sp;
	char	*temp;

	temp = NULL;
	lensp = 0;
	len2 = 0;
	len1 = 0;
	while (ft_isalnum(*(str + len1)))
		++len1;
	while (ft_isspace(*(str + len1 + len2)))
		++len2;
	if ((sp = ft_strnew(len2)) == NULL)
		die();
	ft_memcpy(sp, (str + len1), len2);
	lensp = len2;
	len2 = 0;
	while (*(str + len1 + len2 + lensp) && (len1 + len2 + lensp) < len)
		++len2;
	if ((temp = ft_strnew(len1)) == NULL)
		die();
	ft_memcpy(temp, str, len1);
	ft_memcpy(str, (str + len1 + lensp), len2);
	ft_memcpy(str + len2, sp, lensp);
	ft_memcpy((str + len2 + lensp), temp, len1);
	line->cpos = add - str + len;
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

static	void	tw_chech_space(char *str, int cpos, t_line *line)
{
	int		i;
	int		j;

	i = cpos;
	j = cpos;
	while (*(str + cpos) && ft_isspace(*(str + i)) && i >= 0)
		--i;
	if (i < 0)
		return ;
	while (*(str + cpos) && ft_isspace(*(str + cpos)))
		++cpos;
	if (!*(str + cpos))
	{
		while (*(str + cpos) && ft_isalnum(*(str + i)) && i >= 0)
			--i;
		while (*(str + cpos) && ft_isspace(*(str + i)) && cpos >= 0)
			--i;
		if (i < 0)
			return ;
		while (*(str + cpos) && ft_isalnum(*(str + i)) && i >= 0)
			--i;
		while (*(str + cpos) && ft_isalnum(*(str + cpos)) && i >= 0)
			--cpos;
		tw_trans_words((str + i), str, cpos, line);
	}
}

void			transpose_words(t_line *line)
{
	if (line)
	{
		if (ft_isalnum(*(line->str->s + line->cpos)))
			tw_check_char(line->str->s, line->cpos, line);
		else if (ft_isspace(*(line->str->s + line->cpos)))
			tw_chech_space(line->str->s, line->cpos, line);
	}
}
