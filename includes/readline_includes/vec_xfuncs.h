/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_xfuncs.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelisan </var/spool/mail/vladimir>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 16:50:04 by gmelisan          #+#    #+#             */
/*   Updated: 2019/07/26 19:02:15 by gmelisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VEC_XFUNCS_H
# define VEC_XFUNCS_H

# include "ft_readline.h"

t_vector		vec_xcreate(size_t len, size_t size);
t_vector		vec_xduplicate(t_vector vec, void *(*duplicate)(void *));
void			vec_xaddback(t_vector *vec, void *new);
void			vec_xaddfront(t_vector *vec, void *new);

#endif
