/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_float.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelisan <gmelisan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 11:57:16 by gmelisan          #+#    #+#             */
/*   Updated: 2019/01/29 17:58:50 by gmelisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		add_zeros(t_conversion *conv)
{
	char	*newstr;
	size_t	len;
	size_t	newlen;

	len = ft_strlen(conv->out);
	newlen = 0;
	if (conv->flags.minus)
		conv->flags.zero = 0;
	if (conv->flags.zero && conv->width > len)
		newlen = conv->width - 1;
	if (newlen > len)
	{
		newstr = ft_strnew(newlen);
		ft_memset(newstr, '0', newlen);
		ft_memcpy(newstr + (newlen - len), conv->out, len);
		ft_strdel(&(conv->out));
		conv->out = newstr;
	}
}

static void		add_sign(t_conversion *conv, long double n)
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

static void		add_spaces(t_conversion *conv)
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

void			convert_float(t_conversion *conv, long double n)
{
	if (ft_tolower(conv->type) == 'f')
		number_to_string_f(conv, n);
	else if (ft_tolower(conv->type) == 'e')
		number_to_string_e(conv, n);
	add_zeros(conv);
	add_sign(conv, n);
	add_spaces(conv);
}
