/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_xfuncs.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelisan </var/spool/mail/vladimir>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/06 18:12:50 by gmelisan          #+#    #+#             */
/*   Updated: 2019/07/20 07:38:23 by gmelisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STR_XFUNCS_H
# define STR_XFUNCS_H

# include "ft_readline.h"

t_string	str_xcreate(size_t len);
t_string	str_xduplicate(t_string str);
t_string	str_xcopy(char *s);
t_string	str_xsubstring(t_string str, int start, int len);
void		str_xaddback(t_string *str, char *s, size_t size);
void		str_xaddfront(t_string *str, char *s, size_t size);
void		str_xinsert(t_string *str, int to, char *s, size_t size);


#endif
