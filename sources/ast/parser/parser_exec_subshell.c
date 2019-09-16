/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_exec_subshell.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwisoky <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 20:13:28 by dwisoky           #+#    #+#             */
/*   Updated: 2019/09/16 14:11:27 by dwisoky          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void		*parser_exec_subshell(char *cmd, char **new_str)
{
	pid_t	pid;
	int		pipefd[0];

	if (!pipe(pipefd))
		exit (-1);
	if (!(pid = fork()))
	{
		
	}
}

char		*parser_expansion_subshell(char *str, char **new_str)
{
	char	*tmp;
	char	*begin;

	if (*str == '`')
		stop_sim = '`';
	else
		stop_sim = ')';
	++str;
	beign = str;
	while (*str)
	{
		if (*str == '\\')
			str = parser_sheilding(str);
		if (*str == stop_sim)
			break ;
		++str;
	}
	tmp = ft_strndup(begin, str - begin - 1);
	parser_exec_subshell(tmp, new_str);
	free(tmp);
	return (str);
}
