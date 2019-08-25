/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwisoky <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/25 19:14:53 by dwisoky           #+#    #+#             */
/*   Updated: 2019/08/25 19:16:46 by dwisoky          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

char		*get_left_fd(char *str, int *fd)
{
	while (*str >= '0' && *str <= '9')
	{
		if (*fd > *fd * 10 + (*str - '0') && (*fd = -2))
		{
			*fd = -2;
			while (*str && *str >= '0' && *str <= '9')
				++str;
			break ;
		}
		*fd = *fd * 10 + (*str - '0');
		++str;
	}
	return (str);
}

int			lexer_return_type(char **str, int *type)
{
	if (**str == '<')
		*type = lexer_redir_less(str);
	else if (**str == '>')
		*type = lexer_redir_great(str);
	else if (**str == '&')
		*type = lexer_redir_and(str);
	else
		return (0);
	return (1);
}
