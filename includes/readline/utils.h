/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelisan <gmelisan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/09 15:02:04 by gmelisan          #+#    #+#             */
/*   Updated: 2019/08/20 12:01:07 by gmelisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "ft_readline.h"

void		del_bind_str(void *elem);
void		del_str(void *s);
void		del_pchar(void *s);
int			cmp_pstring(const void *a, const void *b);

#endif
