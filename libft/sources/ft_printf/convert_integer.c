/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_integer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelisan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/28 16:24:16 by gmelisan          #+#    #+#             */
/*   Updated: 2019/01/29 17:53:12 by gmelisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	add_zeros(t_conversion *conv)
{
	char	*newstr;
	size_t	len;
	size_t	newlen;

	len = ft_strlen(conv->out);
	if (conv->flags.minus || conv->prec_set)
		conv->flags.zero = 0;
	if (conv->flags.zero && conv->width > len)
		newlen = conv->width - (get_base(conv->type) == 16 ? 2 : 1);
	else
		newlen = conv->precision;
	if (newlen > len)
	{
		newstr = ft_strnew(newlen);
		ft_memset(newstr, '0', newlen);
		ft_memcpy(newstr + (newlen - len), conv->out, len);
		ft_strdel(&(conv->out));
		conv->out = newstr;
	}
}

static void	add_sign(t_conversion *conv, t_llint n)
{
	char *newstr;

	newstr = NULL;
	if (n < 0)
		newstr = ft_strjoin("-", conv->out);
	else if (conv->flags.plus)
		newstr = ft_strjoin("+", conv->out);
	else if (conv->flags.space)
		newstr = ft_strjoin(" ", conv->out);
	if (newstr)
	{
		ft_strdel(&(conv->out));
		conv->out = newstr;
	}
}

static void	add_altform(t_conversion *conv, t_llint n)
{
	char *newstr;

	newstr = NULL;
	if (ft_tolower(conv->type) == 'x' && n == 0)
		return ;
	if (get_base(conv->type) == 8 && conv->out[0] != '0')
		newstr = ft_strjoin("0", conv->out);
	else if (get_base(conv->type) == 16)
		newstr = ft_strjoin((conv->type == 'X' ? "0X" : "0x"), conv->out);
	else if (get_base(conv->type) == 2)
		newstr = ft_strjoin("0b", conv->out);
	if (newstr)
	{
		ft_strdel(&(conv->out));
		conv->out = newstr;
	}
}

static void	add_spaces(t_conversion *conv)
{
	char	*newstr;
	int		len;
	int		newlen;

	len = ft_strlen(conv->out);
	newlen = conv->width;
	if (newlen > len)
	{
		newstr = prepare_out(conv, newlen);
		if (conv->flags.minus)
			ft_memcpy(newstr, conv->out, len);
		else
			ft_memcpy(newstr + (newlen - len), conv->out, len);
		ft_strdel(&(conv->out));
		conv->out = newstr;
	}
}

void		convert_integer(t_conversion *conv, t_llint n)
{
	int		flag_unsigned;

	conv->out = NULL;
	flag_unsigned = (conv->type == 'd' || conv->type == 'i') ? 0 : 1;
	if (n == 0 && conv->prec_set && conv->precision == 0)
		conv->out = ft_strnew(0);
	else
		conv->out = number_to_string(n, conv, flag_unsigned);
	add_zeros(conv);
	if (!flag_unsigned)
		add_sign(conv, n);
	if ((conv->flags.hash) || conv->type == 'p')
		add_altform(conv, n);
	add_spaces(conv);
}
