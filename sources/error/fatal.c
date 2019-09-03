/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fatal.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelisan <gmelisan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 22:37:13 by gmelisan          #+#    #+#             */
/*   Updated: 2019/09/03 22:51:51 by gmelisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error.h"

void		fatal(const char *msg)
{
	extern int	g_logfd;

	term_restore();
	ft_putstr_fd("\n", STDERR);
	ft_putstr_fd(g_project_name, STDERR);
	ft_putstr_fd(": Fatal error: ", STDERR);
	ft_putstr_fd(msg, STDERR);
	ft_putstr_fd("\n", STDERR);
	if (DEBUG && g_logfd >= 0)
	{
		ft_putstr_fd("! Fatal error: ", g_logfd);
		ft_putstr_fd(msg, g_logfd);
		ft_putstr_fd("\n", g_logfd);
	}
	logclose();
	exit(-1);
}
