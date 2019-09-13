/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_lexem_value.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggwin-go <ggwin-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 20:23:38 by ggwin-go          #+#    #+#             */
/*   Updated: 2019/09/12 20:26:50 by ggwin-go         ###   ########.fr       */
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
	else
		return (")");
}
