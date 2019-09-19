/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del_funcs.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelisan <gmelisan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 14:47:23 by gmelisan          #+#    #+#             */
/*   Updated: 2019/09/19 15:57:45 by gmelisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEL_FUNCS_H
# define DEL_FUNCS_H

# include "libft.h"
# include "ft_string.h"

void		del_bind_str(void *elem);
void		del_str(void *s);
void		del_pchar(void *s);
void		del_undo_one(void *p, size_t i);

#endif
