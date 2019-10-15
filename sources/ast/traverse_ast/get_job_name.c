/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_job_name.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggwin-go <ggwin-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 22:01:59 by ggwin-go          #+#    #+#             */
/*   Updated: 2019/10/15 18:37:46 by ggwin-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

char	*get_job_name(t_lex *lex, t_lex *lex_end)
{
	char	*str;
	char	*tmp;

	str = ft_xstrdup("");
	if (!lex)
		return (str);
	while (lex && lex != lex_end)
	{
		if (lex->type == NEWLINE)
			continue ;
		tmp = (lex->lexem) ? lex->lexem : get_lexem_value(lex->type);
		str = ft_xstrrejoin(str, tmp, 1);
		if (lex->type != IO_NUMBER && lex->next && lex->next != lex_end)
			str = ft_xstrrejoin(str, " ", 1);
		lex = lex->next;
	}
	return (str);
}
