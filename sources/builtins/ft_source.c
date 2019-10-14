/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_source.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwisoky <dwisoky@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/05 17:44:37 by wtalea            #+#    #+#             */
/*   Updated: 2019/10/14 18:23:28 by dwisoky          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

#define FD fd[0]
#define TMP fd[1]
#define USAGE 1
#define NO_SUCH 2
#define HISTORY g_opt.history

extern	t_opt	g_opt;

static	int		error(const char *str, int err_code)
{
	if (err_code == USAGE)
		ft_putendl_fd("source: usage: source filename\n", STDERR);
	else if (err_code == NO_SUCH)
		print_error_vaarg("source: %s: no such file or directory\n", str);
	HISTORY = 1;
	return (1);
}
/*
static	int		find_spaces(char *line)
{
	while (*line)
		if (!ft_isspace(*(line++)))
			return (1);
	return (0);
}
*/
static	void	gnl_exec(char *line, int fd[2])
{
	extern int		g_eof;
	extern t_opt	g_opt;

	g_opt.rl_gnl = 1;
	g_opt.rl_in = FD;
	g_opt.emacs_mode = 0;
	g_opt.vi_mode = 0;
	while (1)
	{
		line = ft_readline("", RL_DEFAULT);
		if (g_eof)
			break ;
		execute_line(line);
	}
	g_eof = 0;
	close(FD);
	g_opt.rl_gnl = 0;
	g_opt.rl_in = 0;
	g_opt.emacs_mode = 1;
}

static	int		check_valid(const char *argv)
{
	struct stat tmp;

	if (!access(argv, R_OK))
	{
		if (!stat(argv, &tmp))
			if (S_ISREG(tmp.st_mode))
				return (1);
	}
	return (0);
}

int				ft_source(int argc, const char **argv)
{
	char	*line;
	int		fd[2];

	line = 0;
	ft_bzero(fd, (sizeof(int) * 2));
	if (argc >= 2)
	{
		HISTORY = 0;
		if (!check_valid(*argv))
			return (error(*argv, NO_SUCH));
		if (check_binary((char *)*argv))
			return (1);
		FD = open(*argv, O_RDONLY);
		if (FD > 0)
			gnl_exec(line, fd);
		else
			return (error(*argv, NO_SUCH));
	}
	else
		return (error(NULL, USAGE));
	HISTORY = 1;
	return (0);
}
