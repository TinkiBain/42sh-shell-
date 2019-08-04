/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_handlers.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelisan </var/spool/mail/vladimir>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/05 21:57:39 by gmelisan          #+#    #+#             */
/*   Updated: 2019/08/04 13:07:48 by gmelisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "signal_handlers.h"

void	sigh_sigsegv(int sig)
{
	if (sig == SIGSEGV)
	{
		term_restore();
		ft_putstr_fd("Segmentation fault\n", STDERR);
		loginfo("SIGSEGV caught, exit");
		loginfo_backtrace();
		logclose();
		exit(1);
	}
}

void	sigh_sigabrt(int sig)
{
	if (sig == SIGABRT)
	{
		term_restore();
		ft_putstr_fd("Aborted.\n", STDERR);
		loginfo("SIGABRT caught, exit");
		loginfo_backtrace();
		logclose();
		exit(1);
	}
}

void	sigh_sigterm(int sig)
{
	if (sig == SIGTERM)
	{
		reset_line(g_line);
		update_line(g_line);
		loginfo("SIGTERM caught, reset line");
	}
}

void	sigh_sigint(int sig)
{
	
	if (sig == SIGINT)
	{
		ft_putstr_fd("^C", STDOUT);
		reset_line(g_line);
		update_line(g_line);
		loginfo("SIGINT caught, reset line");
	}
}

void	sigh_sigwinch(int sig)
{
	if (sig == SIGWINCH)
	{
		loginfo("SIGWINCH caught, new width: %d",
				get_screenwidth());
		update_line(NULL);
	}
}

void	sigh_ignore(int sig)
{
	if (sig)
		return ;
}
