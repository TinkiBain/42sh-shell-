/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_char.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelisan </var/spool/mail/vladimir>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/20 07:11:34 by gmelisan          #+#    #+#             */
/*   Updated: 2019/08/15 06:26:59 by gmelisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "actions.h"

void	delete_char(t_line *line)
{
	int i;

	i = -1;
	while (++i < line->arg)
		str_remove(line->str, line->cpos, 1);
	
}
