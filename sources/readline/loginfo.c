/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loginfo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelisan </var/spool/mail/vladimir>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/02 23:02:35 by gmelisan          #+#    #+#             */
/*   Updated: 2019/08/02 23:33:33 by gmelisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "loginfo.h"

int			g_logfd;

void		logopen(void)
{
	if (!DEBUG)
		return ;
	g_logfd = open(LOGNAME, O_RDWR | O_APPEND | O_CREAT, S_IRWXU);
	loginfo("Start");
}

void		logclose(void)
{
	if (!DEBUG)
		return ;
	loginfo("End");
	close(g_logfd);
}

void		loginfo(char *str, ...)
{
	va_list	ap;

	if (!DEBUG)
		return ;
	va_start(ap, str);
	ft_vfdprintf(g_logfd, str, ap);
	va_end(ap);
	ft_putchar_fd('\n', g_logfd);
}

void		loginfo_line(t_line *line)
{
	char c;

	if (!DEBUG)
		return ;
	c = line->keybuf[0];
	ft_fdprintf(g_logfd,
		"-> (%c) [%d %d %d %d %d %d], str: \"%s\"(%d), pos: %d\n",
		ft_isprint(c) ? c : ' ',
		line->keybuf[0], line->keybuf[1],
		line->keybuf[2], line->keybuf[3],
		line->keybuf[4], line->keybuf[5],
		line->str->s, line->str->len, line->cpos);
}

void		loginfo_backtrace(void)
{
	int		size;
	void	*bt_buffer[BT_BUFSIZE];

	if (!DEBUG)
		return ;
	size = backtrace(bt_buffer, BT_BUFSIZE);
	ft_fdprintf(g_logfd, "Backtrace:\n");
	backtrace_symbols_fd(bt_buffer, size, g_logfd);
}
