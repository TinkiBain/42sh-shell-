/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vi_yank_to_end.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelisan </var/spool/mail/vladimir>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/16 04:22:27 by gmelisan          #+#    #+#             */
/*   Updated: 2019/08/16 04:22:49 by gmelisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "actions.h"

void	vi_yank_to_end(t_line *line)
{
	if (line->str->len > 0)
	{
		str_delete(&line->kill_buffer);
		line->kill_buffer = str_xsubstring(*line->str, line->cpos,
										   line->str->len - line->cpos);
	}
}
