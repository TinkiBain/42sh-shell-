/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xfuncs.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelisan </var/spool/mail/vladimir>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/17 05:55:27 by gmelisan          #+#    #+#             */
/*   Updated: 2019/08/17 14:49:31 by gmelisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef XFUNCS_H
# define XFUNCS_H

# include "libft.h"
# include "ft_string.h"
# include "ft_vector.h"

void		die(void);
void		*xmalloc(size_t size);
void		*ft_xmemalloc(size_t size);
char		*ft_xstrdup(const char *src);
char		*ft_xstrjoin(char const *s1, char const *s2);

t_string	str_xcreate(size_t len);
t_string	str_xduplicate(t_string str);
t_string	str_xcopy(char *s);
t_string	str_xncopy(char *s, int n);
t_string	str_xsubstring(t_string str, int start, int len);
void		str_xaddback(t_string *str, char *s, size_t size);
void		str_xaddfront(t_string *str, char *s, size_t size);
void		str_xinsert(t_string *str, int to, char *s, size_t size);

t_vector	vec_xcreate(size_t len, size_t size);
t_vector	vec_xduplicate(t_vector vec, void *(*duplicate)(void *));
void		vec_xaddback(t_vector *vec, void *new);
void		vec_xaddfront(t_vector *vec, void *new);

#endif
