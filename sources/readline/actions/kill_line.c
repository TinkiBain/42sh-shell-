/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kill_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelisan </var/spool/mail/vladimir>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/20 07:26:37 by gmelisan          #+#    #+#             */
/*   Updated: 2019/08/16 03:38:48 by gmelisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "actions.h"

void	kill_line(t_line *line)
{
	if (line->str->len > 0)
	{
		str_delete(&line->kill_buffer);
		line->kill_buffer = str_xsubstring(*line->str, line->cpos,
										   line->str->len - line->cpos);
		str_remove(line->str, line->cpos, line->str->len - line->cpos);
	}
}
