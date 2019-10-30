/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loginfo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggwin-go <ggwin-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/02 23:02:35 by gmelisan          #+#    #+#             */
/*   Updated: 2019/10/30 20:17:01 by gmelisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "loginfo.h"

int			g_logfd = -1;

void		logopen(void)
{
	char			*path;
	extern t_opt	g_opt;
	struct stat		st;
	char			*lgn;
	struct passwd	*pw;

	if (!DEBUG)
		return ;
	pw = NULL;
	lgn = getlogin();
	if ((lgn) && (pw = getpwnam(lgn)))
	{
		path = ft_strjoin(pw->pw_dir, "/." PROJECT_NAME ".log");
		if (stat(path, &st) == 0 && st.st_size >= LOGSIZE)
			g_logfd = open(path, O_RDWR | O_TRUNC | O_CREAT, S_IRWXU);
		else
			g_logfd = open(path, O_RDWR | O_APPEND | O_CREAT, S_IRWXU);
		if (g_logfd < 0)
			ft_fdprintf(STDERR, "Error while opening logfile: %s\n", path);
		ft_strdel(&path);
	}
	else
		ft_fdprintf(STDERR, "Can't find HOME for logfile");
	loginfo("=== START ===\ntty: %s, pid: %d", ttyname(g_opt.rl_in), getpid());
}

void		logclose(void)
{
	if (!DEBUG || g_logfd < 0)
		return ;
	loginfo("=== EXIT ===");
	close(g_logfd);
}

void		loginfo(const char *str, ...)
{
	va_list	ap;

	if (!DEBUG || g_logfd < 0)
		return ;
	if (g_logfd <= 2 &&
		dup2(g_logfd, 10) != -1)
	{
		close(g_logfd);
		g_logfd = 10;
	}
	va_start(ap, str);
	ft_vfdprintf(g_logfd, str, ap);
	va_end(ap);
	ft_fdprintf(g_logfd, "\n");
}

void		loginfo_vaarg(const char *str, va_list ap)
{
	if (!DEBUG || g_logfd < 0)
		return ;
	if (g_logfd <= 2 &&
		dup2(g_logfd, 10) != -1)
	{
		close(g_logfd);
		g_logfd = 10;
	}
	ft_vfdprintf(g_logfd, str, ap);
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
