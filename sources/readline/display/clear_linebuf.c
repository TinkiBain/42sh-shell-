/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_linebuf.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelisan <gmelisan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/02 17:19:51 by gmelisan          #+#    #+#             */
/*   Updated: 2019/08/20 03:55:50 by gmelisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "display.h"

void	clear_linebuf(void)
{
	str_delarr(&g_buffer.out);
	str_delete(&g_buffer.b);
	vec_delete(&g_buffer.escseqs, del_str);
	str_delete(&g_buffer.original);
	ft_bzero(&g_buffer, sizeof(t_buffer));
}
