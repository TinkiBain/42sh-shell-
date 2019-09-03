/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggwin-go <ggwin-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/27 01:24:52 by gmelisan          #+#    #+#             */
/*   Updated: 2019/09/04 00:53:47 by gmelisan         ###   ########.fr       */
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
	fd = 0;
	if (ac > 1)
		fd = open(av[1], O_RDONLY);
	if (fd > 0)
		g_project_name = ft_xstrdup(av[1]);
	else
		g_project_name = ft_xstrdup((p) ? (p + 1) : av[0]);
	if (fd < 0)
		print_error_exit("No such file or directory", av[1], 127);
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
	fill_g_var_names();
	fill_hash_table();
	logopen();
	g_history = ft_xmemalloc(sizeof(t_history));
	history_load(g_history);
}
