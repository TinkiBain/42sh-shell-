/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jterry <jterry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 16:17:19 by ggwin-go          #+#    #+#             */
/*   Updated: 2019/11/01 18:37:39 by dwisoky          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_H
# define BUILTINS_H

# include "sh.h"
# include "ft_getopt.h"
# include "jobs.h"

/*
**		Built-in functions
*/

int			ft_alias(const char **av);
int			cd_norm(char *path, const char *tmp, int flag);
const char	*cd_check_flag(const char **av, int *flag);
void		*cd_error_invalid_flag(char c);
int			change_dir(char *curpath, const char *av, int flag);
int			ft_cd(const char **av);
int			ft_bg(t_pjobs *local_job, const char *name);
int			ft_cd(const char **av);
int			ft_echo(const char **av);
int			ft_exit(int ac, const char **av);
int			ft_export(const char **av);
int			ft_fc(int ac, const char **av, t_pjobs **local);
int			ft_fg(t_pjobs *local_job, const char *name);
int			ft_hash(char **argv);
int			ft_history(const char **argv);
int			ft_kill(const char **cmd, t_pjobs *local_job, int sig);
int			ft_set(const char **av);
int			ft_source(int argc, const char **argv);
int			ft_test(char **argv);
int			ft_type(const char **av);
int			ft_unalias(const char **av);
int			ft_unset(const char **av);
int			ft_square_test(int argc, const char **argv);
int			ft_help(void);

/*
**		Secondary functions
*/

int		alias_free_all();
int		change_dir(char *curpath, const char *av, int flag);
void	*cd_error_invalid_flag(char c);
int		is_builtin(const char *cmd);

void	ft_getopt_clear(void);
void	ft_getopt_init(char *cmd_name);

#endif
