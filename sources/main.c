/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggwin-go <ggwin-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/01 20:45:11 by ggwin-go          #+#    #+#             */
/*   Updated: 2019/08/31 22:14:42 by ggwin-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"
#include "parser.h"
#include "exec.h"

t_opt		g_opt;
char		**g_var;
char		**g_var_names;
char		*g_project_name;

void		main_readline_loop(void)
{
	t_pars_list	*list;
	char		*buf;
	char		*tmp;

	while (21)
	{
		g_check_nl = 1;
		if (!(buf = ft_readline(get_var_value("PS1"), NULL)))
			break ;
		ft_putstr("\n");
		if (*(tmp = ft_strtrim(buf)))
		{
			list = exec_ast(buf);
			traverse_ast(list);
			g_error_pars = 0;
			parser_free_tree(list);
		}
		else
			free(buf);
		free(tmp);
	}
}

void		main_gnl_loop(int fd, char *filename)
{
	t_pars_list	*list;
	char		*buf;
	char		*tmp;
	int			num_line;

	num_line = 0;
	while (get_next_line(fd, &buf) > 0)
	{
		ft_memdel((void **)&g_project_name);
		g_project_name = ft_strrejoin(filename, ft_itoa(++num_line), 2);
		if (*(tmp = ft_strtrim(buf)))
		{
			list = exec_ast(buf);
			traverse_ast(list);
			g_error_pars = 0;
			parser_free_tree(list);
		}
		else
			ft_memdel((void **)&buf);
		ft_memdel((void **)&tmp);
	}
	ft_memdel((void **)&buf);
}

int			main(int ac, char **av)
{
	int		fd;
	char	*filename;

	shell_init(av[0]);
	if (ac > 1 && (fd = open(*(++av), O_RDONLY)) >= 0)
	{
		filename = ft_strjoin(*av, ": line ");
		main_gnl_loop(fd, filename);
		ft_memdel((void **)&filename);
		close(fd);
	}
	else
	{
		shell_init_readline();
		main_readline_loop();
		history_clear(g_history);
		logclose();
		ft_putstr("exit\n");
	}
	shell_clear();
	return (g_res_exec);
}
