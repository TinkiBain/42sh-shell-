/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggwin-go <ggwin-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/01 20:45:11 by ggwin-go          #+#    #+#             */
/*   Updated: 2019/10/13 12:50:31 by ggwin-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"
#include "parser.h"
#include "builtins.h"
#include "sem.h"

void		main_loop(void)
{
	extern int		g_eof;
	extern t_opt	g_opt;
	char			*line;
	int				i;

	i = 0;
	while (!g_eof)
	{
		init_sem();
		if (!(line = ft_readline((g_opt.rl_gnl == 0 ?
							get_var_value("PS1") : ""), RL_DEFAULT)))
		{
			clear_sem();
			continue ;
		}
		execute_line(line);
		clear_sem();
	}
}

int			main(int ac, char **av)
{
	signal_monitor();
	shell_init(ac, av);
	main_loop();
	shell_clear();
	print_exit();
	return (g_res_exec);
}
