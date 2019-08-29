/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_errno.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggwin-go <ggwin-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/04 10:11:35 by gmelisan          #+#    #+#             */
/*   Updated: 2019/08/29 17:32:19 by ggwin-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_errno.h"

int		g_errno = 0;

static void	print(char *msg)
{
	ft_fdprintf(STDERR, "%s: ", g_project_name);
	if (g_errinfo[0])
		ft_fdprintf(STDERR, "%s: ", g_errinfo);
	ft_fdprintf(STDERR, "%s\n", msg);
	if (g_errinfo[0])
		loginfo("%s (\"%s\")", msg, g_errinfo);
}

static void	print_unk(void)
{
	ft_putstr_fd(g_project_name, STDERR);
	ft_fdprintf(STDERR, ": Unknown error, code %d\n", g_errno);
	loginfo("Unknown error, code %d", g_errno);
}

void		fatal(char *msg)
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
		ft_putstr_fd("Fatal error: ", g_logfd);
		ft_putstr_fd(msg, g_logfd);
		ft_putstr_fd("\n", g_logfd);
	}
	exit(-1);
}

void		printerr(void)
{
	if (!g_errno)
		return ;
	ft_putstr("\n");
	if (g_errno == E_READ)
		print("Read error");
	else
		print_unk();
}
