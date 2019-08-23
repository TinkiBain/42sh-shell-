/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_quotes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwisoky <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/17 18:21:16 by dwisoky           #+#    #+#             */
/*   Updated: 2019/08/17 18:26:57 by dwisoky          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

char	*fill_dquote(char *str)
{
	while (*str)
	{
		if (*str == '\\')
		{
			++str;
			if (*str)
				++str;
			else
				g_error_pars = 2;
		}
		else if (*str == '"')
			return (str + 1);
		else
			++str;
	}
	g_error_pars = 2;
	return (str);
}

char	*fill_quote(char *str)
{
	while (*str)
	{
		if (*str == '\'')
			return (str + 1);
		++str;
	}
	g_error_pars = 2;
	return (str);
}

void	check_quotes(char *str)
{
	while (*str)
	{
		if (*str == '"')
			str = fill_dquote(str + 1);
		else if (*str == '\'')
			str = fill_quote(str + 1);
		else if (*str == '\\')
		{
			++str;
			if (*str)
				++str;
			else
				g_error_pars = 2;
		}
		else
			++str;
	}
}
