/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelisan <gmelisan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 16:17:19 by gmelisan          #+#    #+#             */
/*   Updated: 2019/09/15 06:13:53 by gmelisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_H
# define BUILTINS_H

# include "sh.h"
# include "ft_getopt.h"

typedef struct	s_cmd_opt
{
	t_uint e : 1;
	t_uint l : 1;
	t_uint n : 1;
	t_uint r : 1;
	t_uint s : 1;
}				t_cmd_opt;

int		is_builtin(const char *cmd);

int		bg(t_pjobs *local_job, const char *name);
int		fg(t_pjobs *local_job, const char *name);
int		ft_cd(const char **av, char ***env);
int		ft_echo(const char **av);
int		ft_env(const char **av, char **env);
int		ft_exit(const char **av);
int		ft_export(const char **av);
int		ft_hash(char **argv);
int		ft_kill(const char **cmd, t_pjobs *local_job, int sig);
int		ft_set(const char **av);
int		ft_type(const char **av);
int		ft_unset(const char **av);
int		ft_fc(const char **av);
void	ft_fc_list(t_cmd_opt opt);

#endif
