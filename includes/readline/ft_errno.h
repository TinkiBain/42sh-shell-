/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_errno.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelisan </var/spool/mail/vladimir>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/03 16:39:35 by gmelisan          #+#    #+#             */
/*   Updated: 2019/08/14 17:51:53 by gmelisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ERRNO_H
# define FT_ERRNO_H

# include "ft_readline.h"

enum	e_errno
{
	E_NONE = 0,
	E_MALLOC = 1042,
	E_READ,
	E_KEYBUF_OF,
	E_TERMCAP,
	E_UNK_TERMTYPE,
	E_OPEN
};

extern int	g_errno;

# define ERRINFOLEN		64

char	g_errinfo[ERRINFOLEN];

void	printerr(void);
void	fatal(char *msg);

#endif
