/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggwin-go <ggwin-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/01 20:45:11 by ggwin-go          #+#    #+#             */
/*   Updated: 2019/09/12 20:11:37 by dwisoky          ###   ########.fr       */
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
char		*g_tty;
int			g_res_exec;
int			*g_open_fd;
char		*g_shell_path;
t_alias		*g_alias;

void		execute_line(char *buf)
{
	t_complete_cmd	*list;
	t_lex			*lex;
	char			*tmp;

	tmp = NULL;
	lex = NULL;
	if (*(tmp = ft_strtrim(buf)))
	{
		list = exec_ast(buf, &lex);
		if (list)
			traverse_ast(list);
		parser_free(list);
		lexer_free_all(lex);
	}
	else
		ft_strdel(&buf);
	ft_strdel(&tmp);
}

void		main_loop(void)
{
	char		*line;
	char		*project_name;
	int			i;

	i = 0;
	g_line_num = 1;
	project_name = ft_xstrdup(g_project_name);
	while (!g_exit)
	{
		if (g_opt.rl_in != 0)
		{
			free(g_project_name);
			g_project_name = ft_strrejoin(project_name, ": ", 0);
			g_project_name = ft_strrejoin(g_project_name, ft_itoa(++i), 3);
		}
		g_check_nl = 1;
		if (!(line = ft_readline((g_opt.rl_in == 0 ?
							get_var_value("PS1") : ""), NULL)))
			continue ;
		ft_putstr(g_opt.rl_in == 0 ? "\n" : "");
		execute_line(line);
		g_line_num++;
	}
	ft_strdel(&project_name);
}

int			main(int ac, char **av)
{
	g_alias = (t_alias*)ft_xmalloc(sizeof(t_alias));
	g_alias->head = ft_strdup("ls");
	g_alias->body_alias = ft_strdup("ls -l ");
	g_alias->next = NULL;
	signal_monitor();
	shell_init(ac, av);
	main_loop();
	shell_clear();
	free(g_alias->head);
	free(g_alias->body_alias);
	free(g_alias);
	return (g_res_exec);
}
