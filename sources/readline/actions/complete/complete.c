/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complete.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelisan </var/spool/mail/vladimir>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/09 04:39:02 by gmelisan          #+#    #+#             */
/*   Updated: 2019/08/09 05:47:04 by gmelisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "actions.h"

void		complete(t_line *line)
{
	if (line->complete_fail)
		possible_filename_completions(line);
	complete_filename(line);
}
