/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jterry <jterry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/01 20:45:11 by ggwin-go          #+#    #+#             */
/*   Updated: 2019/09/08 16:29:34 by jterry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"
#include "parser.h"
#include "exec.h"

t_opt		g_opt;
char		**g_var;
char		**g_var_names;
char		*g_project_name;
t_pjobs		*g_pjobs;
t_pjobs		*g_subjob;
int			g_line_num;
int			g_exit;
int			g_wait_flags;

void		execute_line(char *buf)
{
	t_complete_cmd	*list;
	char			*tmp;

	tmp = NULL;
	if (*(tmp = ft_strtrim(buf)))
	{
		list = exec_ast(buf);
		if (list)
			traverse_ast(list);
		parser_free(list);
	}
	else
		ft_strdel(&buf);
	ft_strdel(&tmp);
}

void		main_loop(void)
{
	char		*line;

	g_line_num = 1;
	while (!g_exit)
	{
		g_check_nl = 1;
		if (!(line = ft_readline((g_opt.rl_in == 0 ?
							get_var_value("PS1") : ""), NULL)))
			continue ;
		ft_putstr(g_opt.rl_in == 0 ? "\n" : "");
		execute_line(line);
		g_line_num++;
	}
}

int			main(int ac, char **av)
{
	signal_monitor();
	shell_init(ac, av);
	main_loop();
	shell_clear();
	return (g_res_exec);
}
