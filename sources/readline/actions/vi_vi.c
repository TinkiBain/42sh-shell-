/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vi_vi.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelisan </var/spool/mail/vladimir>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/15 09:00:56 by gmelisan          #+#    #+#             */
/*   Updated: 2019/08/17 06:46:11 by gmelisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "actions.h"

extern char **environ;

static char	**build_argv(char *str)
{
	char	**argv;

	argv = ft_xmemalloc(sizeof(char *) * 3);
	argv[0] = ft_xstrdup("/usr/bin/vim"); /* TODO: take from enviroment? */
	argv[1] = ft_xstrdup(str);
	return (argv);
}

static void	free_argv(char **argv)
{
	free(argv[0]);
	free(argv[1]);
	free(argv);
}

static void	start_vi(char **argv)
{
	pid_t	pid;
	int		status;

	pid = fork();
	if (pid == 0)
	{
		if (execve(argv[0], argv, environ) < 0)
			loginfo("vi_vi(): execve error");
	}
	else if (pid > 0)
	{
		while (1)
		{
			if (waitpid(pid, &status, WUNTRACED) == -1)
			{
				loginfo("vi_vi(): waitpid error");
				return ;
			}
			if (WIFEXITED(status) || WIFSIGNALED(status))
				break ;
		}
	}
	else
		loginfo("vi_vi(): fork error");
}

static void	read_file(int fd, t_line *line)
{
	t_string	str;
	char		c;
	int			ret;

	str = str_xcreate(0);
	while ((ret = read(fd, &c, 1) > 0))
		str_addback(&str, &c, 1);
	if (ret < 0)
		loginfo("vi_vi(): read error");
	else
	{
		str_delete(line->str);
		*line->str = str;
	}
}

void		vi_vi(t_line *line)
{
	int		fd;
	char	**argv;
	
	fd = open(TMP_PATH, O_RDWR | O_CREAT | O_TRUNC, S_IRWXU);
	if (fd < 0)
	{
		loginfo("vi_vi(): open error (%s)", TMP_PATH);
		return ;
	}
	ft_fdprintf(fd, "%s", line->str->s);
	close(fd);
	argv = build_argv(TMP_PATH);
	start_vi(argv);
	free_argv(argv);
	fd = open(TMP_PATH, O_RDWR, S_IRWXU);
	read_file(fd, line);
	close(fd);
}
