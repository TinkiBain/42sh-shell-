/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_errno.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelisan </var/spool/mail/vladimir>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/03 16:39:35 by gmelisan          #+#    #+#             */
/*   Updated: 2019/08/17 05:45:46 by gmelisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ERRNO_H
# define FT_ERRNO_H

# include "ft_readline.h"

enum	e_errno
{
	E_READ = 1042,
};

extern int	g_errno;

# define ERRINFOLEN		64

char	g_errinfo[ERRINFOLEN];

void	printerr(void);
void	fatal(char *msg);

#endif
