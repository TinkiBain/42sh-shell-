/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_unknown.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelisan <gmelisan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 20:23:15 by gmelisan          #+#    #+#             */
/*   Updated: 2019/01/28 12:18:13 by gmelisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	handle_unknown(t_conversion *conv)
{
	int		len;
	char	c;

	if (!conv->type)
		return ;
	len = conv->width ? conv->width : 1;
	c = conv->type;
	conv->out = prepare_out(conv, len);
	if (conv->flags.minus)
		conv->out[0] = c;
	else
		conv->out[len - 1] = c;
	conv->outlen = len;
}
