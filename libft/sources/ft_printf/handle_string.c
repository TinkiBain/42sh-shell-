/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_string.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelisan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/28 16:27:24 by gmelisan          #+#    #+#             */
/*   Updated: 2019/02/01 00:15:10 by gmelisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	convert_string(t_conversion *conv, char *str)
{
	int		len;
	size_t	strsize;

	strsize = ft_strlen(str);
	if (conv->prec_set && conv->precision < strsize)
		strsize = conv->precision;
	len = conv->width > strsize ? conv->width : strsize;
	conv->out = prepare_out(conv, len);
	if (conv->flags.minus)
		ft_memcpy(conv->out, str, strsize);
	else
		ft_memcpy(conv->out + (len - strsize), str, strsize);
	conv->outlen = len;
}

void		handle_string(va_list ap, t_conversion *conv)
{
	char	*str;
	int		nullstr_flag;

	if (conv->type == 'S' || conv->length >= L_L)
		handle_wstring(ap, conv);
	else
	{
		nullstr_flag = 0;
		str = va_arg(ap, char *);
		if (!str)
		{
			str = ft_strdup("(null)");
			nullstr_flag = 1;
		}
		convert_string(conv, str);
		if (nullstr_flag)
			ft_strdel(&str);
	}
}
