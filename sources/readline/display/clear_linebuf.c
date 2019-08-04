/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_linebuf.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelisan </var/spool/mail/vladimir>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/02 17:19:51 by gmelisan          #+#    #+#             */
/*   Updated: 2019/08/02 17:38:57 by gmelisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "display.h"

static void	del(void *str)
{
	str_delete(str);
}

void	clear_linebuf(void)
{
	str_delarr(&g_buffer.out);
	str_delete(&g_buffer.b);
	vec_delete(&g_buffer.escseqs, del);
	str_delete(&g_buffer.original);
	ft_bzero(&g_buffer, sizeof(t_buffer));
}
