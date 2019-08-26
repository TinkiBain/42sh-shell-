/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggwin-go <ggwin-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/25 21:23:33 by dwisoky           #+#    #+#             */
/*   Updated: 2019/08/26 18:02:41 by ggwin-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"
#include "parser.h"
#include "exec.h"

void		lllestb_string(char *buf)
{
	t_pars_list	*list;

	list = exec_ast(buf);
	traverse_ast(list);
	g_error_pars = 0;
	parser_free_tree(list);
}

void		init(void)
{
	extern char			**environ;
	extern t_options	g_options;

	preliminary_check_fd();
	environ = create_copy_env(environ);
	init_g_var();
	fill_g_var_names();
	fill_hash_table();
	logopen();
	g_history = ft_xmemalloc(sizeof(t_history));
	history_load(g_history);
	g_options.enable_color = 1;
	g_options.noclobber = 1;
}

void		end_work(void)
{
	extern char	**environ;

	del_hash();
	history_clear(g_history);
	logclose();
	ft_free_double_ptr_arr((void ***)&environ);
	ft_putstr("exit\n");
}
