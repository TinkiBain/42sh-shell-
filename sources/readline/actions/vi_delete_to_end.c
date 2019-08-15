/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vi_delete_to_end.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelisan </var/spool/mail/vladimir>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/15 08:43:26 by gmelisan          #+#    #+#             */
/*   Updated: 2019/08/15 08:47:37 by gmelisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "actions.h"

void	vi_delete_to_end(t_line *line)
{
	str_remove(line->str, line->cpos, line->str->len - line->cpos);
	line->vi_mode = VI_INSERT;
}
