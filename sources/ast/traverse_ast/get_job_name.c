/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_job_name.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jterry <jterry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 22:01:59 by ggwin-go          #+#    #+#             */
/*   Updated: 2019/09/18 20:09:59 by jterry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

char	*get_job_name(t_lex *lex, t_lex *lex_end, int separator)
{
	char	*str;
	char	*tmp;

	(void)separator;
	str = ft_xstrdup((lex->lexem) ? lex->lexem : get_lexem_value(lex->type));
	while ((lex = lex->next) && lex < lex_end)
	{
		if (lex->type == NEWLINE)
			continue ;
		tmp = ft_strjoin(" ", (lex->lexem) ? lex->lexem
											: get_lexem_value(lex->type));
		str = ft_strrejoin(str, tmp, 3);
	}
/*	if (lex_end->type == PIPE)
	{
		tmp = ft_strjoin(" ", get_lexem_value(lex_end->type));
		str = ft_strrejoin(str, tmp, 3);
	}
	if (separator == JOB)
	{
		tmp = ft_strjoin(" ", get_lexem_value(separator));
		str = ft_strrejoin(str, tmp, 3);
	}*/
	return (str);
}

char	*get_subjob_name(t_command *command)
{
	t_simple_cmd *cmd;

	if ((cmd = command->simple_command))
		return (get_job_name(cmd->lex_begin, cmd->lex_end, 0));
	return (ft_strdup("subjob"));
}
