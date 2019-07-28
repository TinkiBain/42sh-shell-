/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_wstring.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelisan <gmelisan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/28 16:40:26 by gmelisan          #+#    #+#             */
/*   Updated: 2019/02/01 00:14:04 by gmelisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	calc_wslen(wchar_t *ws)
{
	int i;
	int ret;

	i = 0;
	ret = 0;
	while (ws[i])
	{
		ret += sizeof(wchar_t);
		i++;
	}
	return (ret);
}

static int	build_wstring(char *str, wchar_t *ws, t_conversion *conv)
{
	t_uint	i;
	t_uint	j;
	char	s[5];
	int		len;

	i = 0;
	j = 0;
	while (ws[i])
	{
		ft_bzero(s, 5);
		len = ft_wctomb_utf8(s, ws[i]);
		if (len == -1)
			return (-1);
		j += len;
		if (j > conv->precision && conv->prec_set)
			break ;
		ft_strncpy(&str[j - len], s, len);
		i++;
	}
	return (0);
}

static void	convert_wstring(t_conversion *conv, char *str)
{
	size_t	strsize;
	int		len;

	strsize = ft_strlen(str);
	len = conv->width > strsize ? conv->width : strsize;
	conv->out = prepare_out(conv, len);
	if (conv->flags.minus)
		ft_memcpy(conv->out, str, strsize);
	else
		ft_memcpy(conv->out + (len - strsize), str, strsize);
	conv->outlen = len;
}

void		handle_wstring(va_list ap, t_conversion *conv)
{
	wchar_t		*ws;
	char		*str;

	ws = (wchar_t *)va_arg(ap, wchar_t *);
	if (!ws)
		str = ft_strdup("(null)");
	else
	{
		str = ft_strnew(calc_wslen(ws));
		if (build_wstring(str, ws, conv) == -1)
		{
			ft_strdel(&str);
			conv->outlen = -1;
			return ;
		}
	}
	convert_wstring(conv, str);
	ft_strdel(&str);
}
