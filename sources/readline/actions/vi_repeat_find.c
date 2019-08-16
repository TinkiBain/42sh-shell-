/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vi_repeat_find.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelisan </var/spool/mail/vladimir>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/15 12:02:16 by gmelisan          #+#    #+#             */
/*   Updated: 2019/08/15 12:16:29 by gmelisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "actions.h"

void	vi_repeat_find(t_line *line)
{
	if (line->vi.prev_find == VI_FIND_FORWARD)
		vi_find_forward_char(line, line->vi.prev_find_c);
	else if (line->vi.prev_find == VI_FIND_BACKWARD)
		vi_find_backward_char(line, line->vi.prev_find_c);
}
