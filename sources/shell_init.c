/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggwin-go <ggwin-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/27 01:24:52 by gmelisan          #+#    #+#             */
/*   Updated: 2019/09/12 18:00:41 by ggwin-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"
#include "parser.h"
#include "exec.h"

void		preliminary_check_fd(void)
{
	if (fcntl(0, F_GETFL) < -1)
		exit(0);
	if (!isatty(0))
		exit(g_res_exec);
}

void		fill_options(int rl_in)
{
	extern t_opt	g_opt;

	g_opt.enable_color = 1;
	g_opt.noclobber = 1;
	g_opt.vi_mode = 0;
	g_opt.emacs_mode = (rl_in == 0 ? 1 : 0);
	g_opt.rl_in = rl_in;
	g_opt.rl_out = STDERR;
}

static int	get_fd(int ac, char **av)
{
	extern char		*g_project_name;
	char	*p;
	int		fd;

	p = (av[0]) ? ft_strrchr(av[0], '/') : NULL;
	g_project_name = ft_xstrdup((p) ? (p + 1) : av[0]);
	fd = 0;
	if (ac > 1)
	{
		if (check_file_errors(av[1], F_OK) ||
							(fd = open(av[1], O_RDONLY)) < 0)
			exit(g_res_exec);
	}
	if (fd > 0)
	{
		ft_strdel(&g_project_name);
		g_project_name = ft_xstrdup(av[1]);
	}
	return (fd);
}

void		shell_init(int ac, char **av)
{
	extern char	**environ;
	int			fd;

	fd = get_fd(ac, av);
	fill_options(fd);
	preliminary_check_fd();
	environ = create_copy_env(environ);
	init_g_var();
	g_shell_path = ft_strjoin(get_var_value("SHELLHOME"), "/");
	g_shell_path = ft_strrejoin(g_shell_path, g_project_name, 1);
	fill_g_var_names();
	fill_hash_table();
	logopen();
	g_history = ft_xmemalloc(sizeof(t_history));
	g_history->start_index = 1;
	history_load(g_history);
}
