/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vi_clear_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelisan </var/spool/mail/vladimir>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/15 08:48:53 by gmelisan          #+#    #+#             */
/*   Updated: 2019/08/15 08:49:40 by gmelisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "actions.h"

void	vi_clear_line(t_line *line)
{
	ft_bzero(line->str->s, line->str->len);
	line->str->len = 0;
	line->cpos = 0;
	line->vi_mode = VI_INSERT;
}
