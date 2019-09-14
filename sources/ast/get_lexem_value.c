/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_lexem_value.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggwin-go <ggwin-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 20:23:38 by ggwin-go          #+#    #+#             */
/*   Updated: 2019/09/14 14:55:09 by ggwin-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

char	*get_lexem_value(int type)
{
	if (type == NEWLINE)
		return ("newline");
	else if (type == SEMI)
		return (";");
	else if (type == DSEMI)
		return (";;");
	else if (type == AND_IF)
		return ("&&");
	else if (type == OR_IF)
		return ("||");
	else if (type == PIPE)
		return ("|");
	else if (type == JOB)
		return ("&");
	else if (type == LBRACKET)
		return ("(");
	else if (type == RBRACKET)
		return (")");
	else if (type == ANDGREAT)
		return ("&>");
	else if (type == ANDDGREAT)
		return ("&>>");
	else if (type == ANDLESS)
		return ("&<");
	else if (type == CLOBBER)
		return (">|");
	else if (type == GREAT)
		return (">");
	else if (type == DGREAT)
		return (">>");
	else if (type == GREATAND)
		return (">&");
	else if (type == LESS)
		return ("<");
	else if (type == DLESS)
		return ("<<");
	else if (type == TLESS)
		return ("<<<");
	else if (type == DLESSDASH)
		return ("<<-");
	else if (type == LESSAND)
		return ("<&");
	else if (type == LESSGREAT)
		return ("<>");
	// else if (type == DLESSAND)
	// 	return ("<<&");
	else
		return ("NOT_VALID_ID");
}
