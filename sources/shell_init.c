/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelisan <gmelisan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/27 01:24:52 by gmelisan          #+#    #+#             */
/*   Updated: 2019/08/27 01:50:29 by gmelisan         ###   ########.fr       */
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

void		shell_init(int argc, char *argv[])
{
	extern char		**environ;
	extern t_opt	g_opt;

	if (argc > 1 && ft_strequ(argv[1], "-v"))
		g_opt.vi_mode = 1;
	preliminary_check_fd();
	environ = create_copy_env(environ);
	init_g_var();
	fill_g_var_names();
	fill_hash_table();
	logopen();
	g_history = ft_xmemalloc(sizeof(t_history));
	history_load(g_history);
	g_opt.enable_color = 1;
	g_opt.noclobber = 1;
}
