/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vi_vi.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jterry <jterry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/15 09:00:56 by gmelisan          #+#    #+#             */
/*   Updated: 2019/09/13 18:53:00 by jterry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "actions.h"

static char	**build_argv(char *str)
{
	char	**argv;

	argv = ft_xmemalloc(sizeof(char *) * 3);
	argv[0] = ft_xstrdup(get_var_value("TEXTEDITOR"));
	if (!argv[0])
		argv[0] = ft_xstrdup(DEFAULT_TEXTEDITOR);
	argv[1] = ft_xstrdup(str);
	return (argv);
}

static void	free_argv(char **argv)
{
	ft_strdel(&argv[0]);
	ft_strdel(&argv[1]);
	free(argv);
}

static void	start_vi(char **argv)
{
	pid_t		pid;
	int			status;
	extern char	**environ;
	t_pjobs		*local;

	pid = fork();
	local = jobs_startet(ft_xstrdup("vi mode"), 0);
	ljobs_startet("vi mode", local->flag, local->num, pid);
	if (pid == 0)
	{
		if (execve(argv[0], argv, environ) < 0)
			loginfo("vi_vi(): execve error");
	}
	else if (pid > 0)
	{
		while (1)
		{
			if (ft_waitpid(pid))
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
