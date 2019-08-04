/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xmalloc.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelisan </var/spool/mail/vladimir>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/06 18:26:52 by gmelisan          #+#    #+#             */
/*   Updated: 2019/08/01 07:06:15 by gmelisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef XMALLOC_H
# define XMALLOC_H

# include "ft_readline.h"

void		die(void);
void		*xmalloc(size_t size);
void		*ft_xmemalloc(size_t size);

extern int	g_logfd;

#endif
