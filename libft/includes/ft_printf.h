/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelisan <gmelisan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/25 15:56:36 by gmelisan          #+#    #+#             */
/*   Updated: 2019/08/25 21:41:45 by gmelisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** format: %[flags][width][.precision][length]type
** This implementation is BSD-like, meaning all conversion modifiers
** can be specified in random order.
*/

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include <wchar.h>
# include "libft.h"

# define USE_COLORS		1

# define COLOR_BLACK	"\033[0;30m"
# define COLOR_RED		"\033[0;31m"
# define COLOR_GREEN	"\033[0;32m"
# define COLOR_YELLOW	"\033[0;33m"
# define COLOR_BLUE		"\033[0;34m"
# define COLOR_PURPLE	"\033[0;35m"
# define COLOR_CYAN		"\033[0;36m"
# define COLOR_EOC		"\033[0m"

typedef unsigned char			t_uchar;
typedef unsigned int			t_uint;
typedef unsigned long int		t_ulint;
typedef long long int			t_llint;
typedef unsigned long long int	t_ullint;

/*
** ll, h, l, ll, L
** order matters and means priority when ft_printf finds multiple lengths
*/

enum	e_length {L_NONE, L_HH, L_H, L_L, L_Z, L_LL, L_J, L_LB};

typedef struct	s_conversion
{
	struct
	{
		t_uint	hash	: 1;
		t_uint	zero	: 1;
		t_uint	minus	: 1;
		t_uint	space	: 1;
		t_uint	plus	: 1;
	}				flags;
	t_uint			width;
	t_uint			precision;
	t_uchar			prec_set;
	enum e_length	length;
	t_uchar			type;
	char			*out;
	int				outlen;
}				t_conversion;

int				ft_printf(const char *format, ...);
int				ft_vprintf(const char *format, va_list ap);
int				ft_fdprintf(int fd, const char *format, ...);
int				ft_vfdprintf(int fd, const char *format, va_list ap);

t_conversion	*get_conversion(va_list ap, const char *format, int *i);
void			get_flags(t_conversion *conv, const char *format, int *i);
void			get_width(va_list ap, t_conversion *conv,
							const char *format, int *i);
void			get_precision(va_list ap, t_conversion *conv,
								const char *format, int *i);
void			get_length(t_conversion *conv, const char *format, int *i);

int				handle_conversion(va_list ap, t_conversion *conv);
void			handle_unknown(t_conversion *conv);
void			handle_integer(va_list ap, t_conversion *conv);
void			convert_integer(t_conversion *conv, t_llint n);
char			*number_to_string(t_llint n, t_conversion *conv,
									int flag_unsigned);
int				get_base(char c);
void			handle_float(va_list ap, t_conversion *conv);
void			convert_float(t_conversion *conv, long double n);
void			number_to_string_f(t_conversion *conv, long double n);
void			number_to_string_e(t_conversion *conv, long double n);
void			round_str(char *str, int i, int carry);
void			normalize_f(long double *n, int *digits);

void			handle_char(va_list ap, t_conversion *conv);
void			handle_wchar(va_list ap, t_conversion *conv);
int				ft_wctomb_utf8(char *s, wchar_t wc);
void			handle_string(va_list ap, t_conversion *conv);
void			handle_wstring(va_list ap, t_conversion *conv);

void			clear_conversion(t_conversion **conv);

char			*prepare_out(t_conversion *conv, int len);

int				handle_color(char *color_before, char *color_after, int size);
char			*get_color(const char *format, int i);

#endif
