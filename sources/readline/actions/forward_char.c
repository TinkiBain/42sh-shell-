/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forward_char.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelisan </var/spool/mail/vladimir>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/20 07:15:31 by gmelisan          #+#    #+#             */
/*   Updated: 2019/08/05 20:38:12 by gmelisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "actions.h"

void	forward_char(t_line *line)
{
	if (line->vi_mode && line->cpos == (int)line->str->len - 1)
		return ;
	if (line->cpos < (int)line->str->len)
		line->cpos++;
}
