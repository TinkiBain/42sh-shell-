/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggwin-go <ggwin-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/27 01:24:52 by gmelisan          #+#    #+#             */
/*   Updated: 2019/08/31 20:52:34 by ggwin-go         ###   ########.fr       */
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

void		shell_init_readline(void)
{
	logopen();
	g_history = ft_xmemalloc(sizeof(t_history));
	history_load(g_history);
}

void		shell_init(char *project_name)
{
	extern t_opt	g_opt;
	extern char		**environ;
	extern char		*g_project_name;
	char			*p;

	p = (project_name) ? ft_strrchr(project_name, '/') : NULL;
	g_project_name = ft_xstrdup((p) ? (p + 1) : project_name);
	g_opt.enable_color = 1;
	g_opt.noclobber = 1;
	preliminary_check_fd();
	environ = create_copy_env(environ);
	init_g_var();
	fill_g_var_names();
	fill_hash_table();
}
