/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggwin-go <ggwin-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/03 20:40:22 by dwisoky           #+#    #+#             */
/*   Updated: 2019/09/10 19:31:31 by ggwin-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXEC_H
# define EXEC_H

# include "jobs.h"
# include "parser.h"
# include "lexer.h"

int			call_exec(const char **av, char ***env);
int			is_builtin(const char *cmd);
int			bg(t_pjobs *local_job, const char *name);
int			fg(t_pjobs *local_job, const char *name);
int			ft_cd(const char **av, char ***env);
int			ft_echo(const char **av);
int			ft_env(const char **av, char **env);
int			ft_exit(const char **av);
int			ft_export(const char **av);
int			ft_hash(char **argv);
int			ft_kill(const char **cmd, t_pjobs *local_job, int sig);
int			ft_set(const char **av);
int			ft_type(const char **av);
int			ft_unset(const char **av);
int			change_dir_with_flag(const char *dir);
int			change_dir_without_flag(const char *dir);
int			cd_error(const char *dir);
int			ft_fc(const char **av);
void		*cd_error_invalid_flag(char c);

#endif
