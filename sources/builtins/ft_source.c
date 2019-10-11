/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_source.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wtalea <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/05 17:44:37 by wtalea            #+#    #+#             */
/*   Updated: 2019/10/11 18:47:35 by gmelisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

#define FD fd[0]
#define TMP fd[1]
#define USAGE 1
#define NO_SUCH 2

static	int		error(const char *str, int err_code)
{
	if (err_code == USAGE)
		ft_putendl_fd("source: usage: source filename\n", STDERR);
	else if (err_code == NO_SUCH)
		print_error_vaarg("source: %s: no such file or directory\n", str);
	return (1);
}

static	int		find_spaces(char *line)
{
	while (*line)
		if (!ft_isspace(*(line++)))
			return (1);
	return (0);
}

static	void	gnl_exec(char *line, int fd[2])
{
	TMP = dup(STDIN);
	dup2(FD, STDIN);
	while (get_next_line(STDIN, &line))
		if (line)
		{
			if (!line)
				exit(-1);
			if (find_spaces(line))
				execute_line(line);
			else
				free(line);
		}
	dup2(TMP, STDIN);
	close(FD);
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
	return (0);
}
