/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loginfo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggwin-go <ggwin-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/02 23:02:35 by gmelisan          #+#    #+#             */
/*   Updated: 2019/09/01 17:42:03 by gmelisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "loginfo.h"

int			g_logfd;

void		logopen(void)
{
	char			*path;
	extern t_opt	g_opt;

	if (!DEBUG)
		return ;
	path = tdq(ft_xstrdup(get_var_value("LOGPATH")));
	g_logfd = open(path, O_RDWR | O_APPEND | O_CREAT, S_IRWXU);
	if (g_logfd < 0)
	{
		g_logfd = open(DEF_LOG_PATH, O_RDWR | O_APPEND | O_CREAT, S_IRWXU);
		if (g_logfd < 0)
			ft_fdprintf(STDERR, "Error while opening logfile: %s\n",
															DEF_LOG_PATH);
		loginfo("Error while opening logfile: %s", path);
	}
	ft_strdel(&path);
	loginfo("logopen()");
	loginfo("tty: %s", ttyname(g_opt.rl_in));
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
	c = line->keybuf.s[0];
	ft_fdprintf(g_logfd, "-> (%c) ", ft_isprint(c) ? c : ' ');
	if (!line->vi_mode)
		ft_fdprintf(g_logfd, "EMA ");
	else if (line->vi_mode == VI_INSERT)
		ft_fdprintf(g_logfd, "VII ");
	else if (line->vi_mode == VI_COMMAND)
		ft_fdprintf(g_logfd, "VIC ");
	else if (!line->vi_mode && !line->emacs_mode)
		ft_fdprintf(g_logfd, "RAW ");
	ft_fdprintf(g_logfd,
		"[%d %d %d %d %d %d], str: \"%s\"(%d), pos: %d, kill_buf: %s",
				str_get(line->keybuf, 0), str_get(line->keybuf, 1),
				str_get(line->keybuf, 2), str_get(line->keybuf, 3),
				str_get(line->keybuf, 4), str_get(line->keybuf, 5),
				line->str->s, line->str->len, line->cpos, line->kill_buffer.s);
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
