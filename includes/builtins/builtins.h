/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggwin-go <ggwin-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 16:17:19 by gmelisan          #+#    #+#             */
/*   Updated: 2019/09/29 13:08:34 by ggwin-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_H
# define BUILTINS_H

# include "sh.h"
# include "ft_getopt.h"

int		is_builtin(const char *cmd);

void	ft_getopt_init(char *cmd_name);
void	ft_getopt_clear(void);

int		change_dir(char *curpath, const char *av, int flag);
int		ft_cd(const char **av);
int		ft_bg(t_pjobs *local_job, const char *name);
int		ft_fg(t_pjobs *local_job, const char *name);
int		ft_echo(const char **av);
int		ft_env(const char **av, char **env);
int		ft_exit(const char **av);
int		ft_export(const char **av);
int		ft_hash(char **argv);
int		ft_kill(const char **cmd, t_pjobs *local_job, int sig);
int		ft_set(const char **av);
int		ft_type(const char **av);
int		ft_unset(const char **av);
int		ft_fc(const char **av, int ac);
int		ft_test(char **argv);

#endif
