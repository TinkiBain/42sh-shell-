/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   call_exec.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggwin-go <ggwin-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 22:41:23 by ggwin-go          #+#    #+#             */
/*   Updated: 2019/10/11 15:24:09 by gmelisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

/*
**	When first execve() in function call_nonbuilin_exec() return -1
**	we are calling our shell for execute script.
*/

static int		call_nonbuilin_exec(const char *path, char *const *av)
{
	char		*argv[3];
	char		*shell_path;
	extern char	**environ;

	if (execve(path, av, environ) == -1)
	{
		shell_path = ft_xstrjoin(get_var_value("SHELLHOME"), "/");
		shell_path = ft_strrejoin(shell_path, g_project_name, 1);
		argv[0] = g_project_name;
		argv[1] = av[0];
		argv[2] = NULL;
		if (execve(shell_path, (char *const *)argv, environ) == -1)
			exit(-1);
	}
	return (0);
}

static int		call_if_other_builtin(const char **av, int ac, t_pjobs *local)
{
	if (ft_strequ(*av, "fc"))
		return (ft_fc(av, ac, local));
	else if (ft_strequ(*av, "jobs"))
		return (jobs(g_pjobs, -1, *(av + 1)));
	else if (ft_strequ(*av, "fg"))
		return (ft_fg(g_pjobs, *(av + 1)));
	else if (ft_strequ(*av, "bg"))
		return (ft_bg(g_pjobs, *(av + 1)));
	else if (ft_strequ(*av, "kill"))
		return (ft_kill(av + 1, g_pjobs, 15));
	else if (ft_strequ(*av, "alias"))
		return (ft_alias(av + 1));
	else if (ft_strequ(*av, "unalias"))
		return (ft_unalias(av + 1));
	else if (ft_strequ(*av, "test"))
		return (ft_test((char **)av + 1));
	else if (ft_strequ(*av, "history"))
		return (ft_history(av + 1));
	return (0);
}

static int		call_if_builtin(const char **av, int ac, t_pjobs *local)
{
	if (**av == '%')
		return (ft_fg(g_pjobs, *av));
	else if (ft_strequ(*av, "exit"))
		return (ft_exit(av + 1));
	else if (ft_strequ(*av, "cd"))
		return (ft_cd(av + 1));
	else if (ft_strequ(*av, "echo"))
		return (ft_echo(av + 1));
	else if (ft_strequ(*av, "set"))
		return (ft_set(av + 1));
	else if (ft_strequ(*av, "unset"))
		return (ft_unset(av + 1));
	else if (ft_strequ(*av, "hash"))
		return (ft_hash((char **)av));
	else if (ft_strequ(*av, "type"))
		return (ft_type(av + 1));
	else if (ft_strequ(*av, "export"))
		return (ft_export(av + 1));
	else if (ft_strequ(*av, "source"))
		return (ft_source(ac, av + 1));
	else if (ft_strequ(*av, "."))
		return (ft_source(ac, av + 1));
	return (call_if_other_builtin(av, ac, local));
}

int				call_exec(const char **av, int ac, t_pjobs *local)
{
	char		*p;
	int			res;
	extern char	**g_var;
	extern char	**g_func_defs;

	if ((res = is_builtin(*av)) == 1)
	{
		g_res_exec = call_if_builtin(av, ac, local);
		return (g_res_exec);
	}
	else
		res = check_cmd(*av);
	if (res == 0)
	{
		if ((p = ft_getenv(*av, g_func_defs, ft_strlen(*av))))
		{
			call_subshell(ft_xstrdup(p), local);
			exit(g_res_exec);
		}
		else if ((p = get_bin((char *)*av)))
			return (call_nonbuilin_exec((const char *)p, (char *const *)av));
		else if (ft_strchr(*av, '/'))
			return (call_nonbuilin_exec(*av, (char *const *)av));
	}
	return (127);
}
