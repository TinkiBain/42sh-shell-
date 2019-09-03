/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jterry <jterry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/01 20:45:11 by ggwin-go          #+#    #+#             */
/*   Updated: 2019/09/04 00:07:34 by gmelisan         ###   ########.fr       */
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

void		execute_line(char *buf)
{
	t_pars_list	*list;
	char		*tmp;

	tmp = NULL;
	if (*(tmp = ft_strtrim(buf)))
	{
		list = exec_ast(buf);
		traverse_ast(list);
		g_error_pars = 0;
		parser_free_tree(list);
	}
	else
		ft_strdel(&buf);
	ft_strdel(&tmp);
}

void		main_loop(void)
{
	char		*line;

	g_line_num = 1;
	while (42)
	{
		g_check_nl = 1;
		if (!(line = ft_readline((g_opt.rl_in == 0 ?
							get_var_value("PS1") : ""), NULL)))
			break ;
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
