/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelisan <gmelisan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 21:23:18 by gmelisan          #+#    #+#             */
/*   Updated: 2019/08/17 14:17:28 by gmelisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STRING_H
# define FT_STRING_H

# include "libft.h"

# define STR_DEFBUFSIZE		32

typedef struct	s_string
{
	char		*s;
	size_t		len;
	size_t		alloc;
}				t_string;

t_string		str_create(size_t len);
t_string		str_duplicate(t_string str);
t_string		str_copy(char *s);
t_string		str_ncopy(char *s, int n);

t_string		str_substring(t_string str, int start, int len);

void			str_zero(t_string *str);
void			str_delete(t_string *str);
void			str_delarr(t_string **str);

int				str_fixlen(t_string *str);
char			str_get(t_string str, int i);
int				str_compare(t_string str1, t_string str2);

t_string		*str_split(t_string str, int (*isdelim)(int));

t_string		*str_addback(t_string *str, char *s, size_t size);
t_string		*str_addfront(t_string *str, char *s, size_t size);
void			str_remove(t_string *str, int from, int n);
t_string		*str_insert(t_string *str, int to, char *s, size_t size);

#endif
