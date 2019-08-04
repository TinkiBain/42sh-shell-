/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_errno.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelisan </var/spool/mail/vladimir>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/04 10:11:35 by gmelisan          #+#    #+#             */
/*   Updated: 2019/07/06 15:03:47 by gmelisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_errno.h"

int		g_errno = 0;

void	printerr(void)
{
	if (!g_errno)
		return ;
	else if (g_errno == ERROR_MALLOC)
		ft_fdprintf(STDERR, "Malloc error");
	else if (g_errno == ERROR_READ)
		ft_fdprintf(STDERR, "Read error");
	else if (g_errno == ERROR_KEYBUF_OF)
		ft_fdprintf(STDERR, "Key buffer overflow");
	else if (g_errno == ERROR_TERMCAP)
		ft_fdprintf(STDERR, "Termcap error");
	else if (g_errno == ERROR_UNK_TERMTYPE)
		ft_fdprintf(STDERR, "Unknown terminal");	
}
