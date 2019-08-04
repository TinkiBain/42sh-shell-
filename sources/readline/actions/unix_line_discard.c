/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unix_line_discard.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelisan </var/spool/mail/vladimir>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/20 07:27:12 by gmelisan          #+#    #+#             */
/*   Updated: 2019/07/20 09:17:23 by gmelisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "actions.h"

void	unix_line_discard(t_line *line)
{
	if (line->str->len > 0)
	{
		str_delete(&line->kill_buffer);
		line->kill_buffer = str_xsubstring(*line->str, 0, line->cpos);
		ft_memmove(line->str->s, line->str->s + line->cpos,
				   line->str->len - line->cpos);
		ft_bzero(line->str->s + line->str->len - line->cpos, line->cpos);
		line->str->len -= line->cpos;
		line->cpos = 0;
	}
}
