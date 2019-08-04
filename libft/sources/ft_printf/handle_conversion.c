/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_conversion.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelisan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/26 21:17:44 by gmelisan          #+#    #+#             */
/*   Updated: 2019/01/28 12:14:34 by gmelisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	is_integer(t_uchar c)
{
	if (c == 'd' || c == 'D' || c == 'i' ||
		c == 'u' || c == 'U' ||
		c == 'o' || c == 'O' ||
		c == 'x' || c == 'X' ||
		c == 'b' || c == 'p')
		return (1);
	return (0);
}

static int	is_float(t_uchar c)
{
	if (c == 'f' || c == 'F' ||
		c == 'e' || c == 'E')
		return (1);
	return (0);
}

int			handle_conversion(va_list ap, t_conversion *conv)
{
	if (!conv)
		return (0);
	if (is_integer(conv->type))
		handle_integer(ap, conv);
	else if (is_float(conv->type))
		handle_float(ap, conv);
	else if (ft_tolower(conv->type) == 'c')
		handle_char(ap, conv);
	else if (ft_tolower(conv->type) == 's')
		handle_string(ap, conv);
	else
		handle_unknown(conv);
	return (conv->outlen);
}

void		clear_conversion(t_conversion **conv)
{
	ft_strdel(&(*conv)->out);
	ft_memdel((void **)conv);
}
