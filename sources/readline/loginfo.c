/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loginfo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelisan </var/spool/mail/vladimir>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/02 23:02:35 by gmelisan          #+#    #+#             */
/*   Updated: 2019/08/09 17:51:18 by gmelisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "loginfo.h"

int			g_logfd;

void		logopen(void)
{
	char *abspath;

	if (!DEBUG)
		return ;
	if (!(abspath = convert_tilde(LOG_PATH)))
	{
		g_logfd = open(DEFAULT_LOG_PATH, O_RDWR | O_APPEND | O_CREAT, S_IRWXU);
		if (g_logfd < 0)
			ft_memcpy(g_errinfo, DEFAULT_LOG_PATH, ft_strlen(DEFAULT_LOG_PATH));
	}
	else if (
		(g_logfd = open(abspath, O_RDWR | O_APPEND | O_CREAT, S_IRWXU)) < 0)
		ft_memcpy(g_errinfo, abspath, ft_strlen(abspath));
	ft_strdel(&abspath);
	if (g_logfd < 0)
		g_errno = ERROR_OPEN;
	else
		loginfo("logopen()");
}

void		logclose(void)
{
	if (!DEBUG || g_logfd < 0)
		return ;
	loginfo("logclose()");
	close(g_logfd);
}

void		loginfo(char *str, ...)
{
	va_list	ap;

	if (!DEBUG || g_logfd < 0)
		return ;
	va_start(ap, str);
	ft_vfdprintf(g_logfd, str, ap);
	va_end(ap);
	ft_fdprintf(g_logfd, "\n");
}

void		loginfo_line(t_line *line)
{
	char c;

	if (!DEBUG || g_logfd < 0)
		return ;
	c = line->keybuf[0];
	ft_fdprintf(g_logfd,
		"-> (%c) [%d %d %d %d %d %d], str: \"%s\"(%d), pos: %d ",
		ft_isprint(c) ? c : ' ',
		line->keybuf[0], line->keybuf[1],
		line->keybuf[2], line->keybuf[3],
		line->keybuf[4], line->keybuf[5],
		line->str->s, line->str->len, line->cpos);
	if (!line->vi_mode)
		ft_fdprintf(g_logfd, "emacs");
	else if (line->vi_mode == VI_INSERT)
		ft_fdprintf(g_logfd, "vi insert");
	else if (line->vi_mode == VI_COMMAND)
		ft_fdprintf(g_logfd, "vi command");
	ft_fdprintf(g_logfd, "\n");
}

void		loginfo_backtrace(void)
{
	int		size;
	void	*bt_buffer[BT_BUFSIZE];

	if (!DEBUG || g_logfd < 0)
		return ;
	size = backtrace(bt_buffer, BT_BUFSIZE);
	ft_fdprintf(g_logfd, "Backtrace:\n");
	backtrace_symbols_fd(bt_buffer, size, g_logfd);
}
