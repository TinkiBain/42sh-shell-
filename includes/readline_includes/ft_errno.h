/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_errno.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelisan </var/spool/mail/vladimir>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/03 16:39:35 by gmelisan          #+#    #+#             */
/*   Updated: 2019/07/16 21:50:58 by gmelisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ERRNO_H
# define FT_ERRNO_H

# include "ft_readline.h"

enum	e_errno
{
	ERROR_NONE = 0,
	ERROR_MALLOC = 1042,
	ERROR_READ,
	ERROR_KEYBUF_OF,
	ERROR_TERMCAP,
	ERROR_UNK_TERMTYPE,
	ERROR_OPENHIST,
	ERROR_GNLHIST
};

extern int	g_errno;

# define ERRINFOLEN		64

char	g_errinfo[ERRINFOLEN];

void	printerr(void);

#endif
