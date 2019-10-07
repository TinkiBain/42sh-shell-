/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   globing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwisoky <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/06 14:56:52 by dwisoky           #+#    #+#             */
/*   Updated: 2019/10/07 17:41:25 by dwisoky          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "globing.h"

int			globing_asterisk(char *str_gl, char *str)
{
	int		i;

	i = 0;
	while (*str_gl == '*')
		++str_gl;
	while (str && !i && *str)
	{
		if (*str_gl == '\\')
		{
			++str_gl;
			str = ft_strchr(str, *str_gl);
		}
		else if (*str_gl != '?')
			str = ft_strchr(str, *str_gl);
		i = globing(str_gl, str);
		if (str && *str)
			++str;
	}
	return (i);
}

int			globing_brackets_find_char(char *str_gl, char *end, char *str)
{
	int		flag;
	char	begin_char;
	char	end_char;

	++str_gl;
	flag = 0;
	if (*str_gl == '!')
	{
		flag = 1;
		++str_gl;
	}
	while (*str_gl != ']')
	{
		if (*str_gl == *str)
			return (flag ? 0 : globing(end, str + 1));
		else if (*(str_gl + 1) == '-' && *(str_gl + 2) != ']')
		{
			begin_char = *str_gl;
			str_gl += 2;
			end_char = *str_gl;
			if (*str <= end_char && *str >= begin_char)
				return (flag ? 0 : globing(end, str + 1));
		}
		++str_gl;
	}
	if (flag)
		return (globing(end, str + 1));
	return (0);
}

int			globing_brackets(char *str_gl, char *str)
{
	char	*tmp;
	char	*src;

	tmp = str_gl;
	tmp = ft_strchr(tmp, ']');
	if (!tmp)
	{
		if (*str_gl == *str)
			return (globing(str_gl + 1, str + 1));
		else
			return (0);	
	}
	src = str_gl + 1;
	src = ft_strchr(tmp, '[');
	if (!src || src > tmp)
		return (globing_brackets_find_char(str_gl, tmp + 1, str));
	else
	{
		if (*str_gl == *str)
			return (globing(str_gl + 1, str + 1));
		else
			return (0);
	}
}

int			globing(char *str_gl, char *str)
{
	if (!str)
		return (0);
	while (*str && *str_gl)
	{
		if (*str_gl == '*')
			return (globing_asterisk(str_gl, str));
		else if (*str_gl == '?')
		{
			++str_gl;
			++str;
		}
		else if (*str_gl == '[')
			return (globing_brackets(str_gl, str));
		else if (*str_gl != *str)
			break ;
		else
		{
			++str_gl;
			++str;
		}	
	}
	if (*str || *str_gl)
		return (0);
	return (1);
}
