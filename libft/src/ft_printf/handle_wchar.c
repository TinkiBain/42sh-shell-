/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_wchar.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelisan <gmelisan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/25 13:07:42 by gmelisan          #+#    #+#             */
/*   Updated: 2019/01/30 14:28:35 by gmelisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_wctomb_utf8_2(char *s, wchar_t wc)
{
	s[1] = (wc & 0x3F) | 0x80;
	s[0] = ((wc >> 6) & 0x1F) | 0xC0;
	return (2);
}

static int	ft_wctomb_utf8_3(char *s, wchar_t wc)
{
	s[2] = (wc & 0x3F) | 0x80;
	s[1] = ((wc >> 6) & 0x3f) | 0x80;
	s[0] = ((wc >> 12) & 0xF) | 0xE0;
	return (3);
}

static int	ft_wctomb_utf8_4(char *s, wchar_t wc)
{
	s[3] = (wc & 0x3F) | 0x80;
	s[2] = ((wc >> 6) & 0x3F) | 0x80;
	s[1] = ((wc >> 12) & 0x3F) | 0x80;
	s[0] = ((wc >> 18) & 0x07) | 0xF0;
	return (4);
}

int			ft_wctomb_utf8(char *s, wchar_t wc)
{
	if ((t_uint)wc <= 0x7f)
	{
		s[0] = wc;
		return (1);
	}
	if (((t_uint)wc <= 0x9f &&
		(t_uint)wc != 0x24 && (t_uint)wc != 0x40 && (t_uint)wc != 0x60) ||
		((t_uint)wc >= 0xd800 && (t_uint)wc <= 0xdfff))
		return (-1);
	else if ((t_uint)wc <= 0x7FF)
		return (ft_wctomb_utf8_2(s, wc));
	else if ((t_uint)wc <= 0xFFFF)
		return (ft_wctomb_utf8_3(s, wc));
	else if ((t_uint)wc <= 0x10FFFF)
		return (ft_wctomb_utf8_4(s, wc));
	else
		return (-1);
}

void		handle_wchar(va_list ap, t_conversion *conv)
{
	wint_t	wc;
	char	s[5];
	int		wclen;
	int		len;

	wc = (wint_t)va_arg(ap, wint_t);
	ft_bzero(s, 5);
	wclen = ft_wctomb_utf8(s, wc);
	conv->outlen = wclen;
	if (wclen == -1)
		return ;
	len = conv->width > (t_uint)wclen ? (int)conv->width : wclen;
	conv->out = prepare_out(conv, len);
	if (conv->flags.minus)
		ft_memcpy(conv->out, s, wclen);
	else
		ft_memcpy(conv->out + (len - wclen), s, wclen);
	conv->outlen = len;
}
