/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vi_delete_to_end_save.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelisan </var/spool/mail/vladimir>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/16 03:36:11 by gmelisan          #+#    #+#             */
/*   Updated: 2019/08/16 03:43:35 by gmelisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "actions.h"

void	vi_delete_to_end_save(t_line *line)
{
	if (line->str->len > 0)
	{
		str_delete(&line->kill_buffer);
		line->kill_buffer = str_xsubstring(*line->str, line->cpos,
										   line->str->len - line->cpos);
		str_remove(line->str, line->cpos, line->str->len - line->cpos);
	}
}
