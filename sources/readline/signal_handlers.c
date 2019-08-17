/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_handlers.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelisan </var/spool/mail/vladimir>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/05 21:57:39 by gmelisan          #+#    #+#             */
/*   Updated: 2019/08/17 17:15:38 by gmelisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "signal_handlers.h"

void	sigh_sigsegv(int sig)
{
	if (sig == SIGSEGV)
	{
		term_restore();
		ft_putstr_fd("\nSegmentation fault\n", STDERR);
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
		ft_putstr_fd("\nAborted.\n", STDERR);
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

void	sigh_sigwinch(int sig)
{
	if (sig == SIGWINCH)
	{
		loginfo("SIGWINCH caught: [%dx%d]",
				get_screen_width(), get_screen_height());
		update_line(NULL);
	}
}

void	sigh_ignore(int sig)
{
	loginfo("Caught signal %d", sig);
	ft_putchar('\n');
}
