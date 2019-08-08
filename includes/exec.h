/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggwin-go <ggwin-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/03 20:40:22 by dwisoky           #+#    #+#             */
/*   Updated: 2019/08/08 20:25:14 by ggwin-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXEC_H
# define EXEC_H

#include "parser.h"
#include "lexer.h"

int			g_res_exec;
int			g_fd[3];

int			call_exec(const char **av, char ***env);
int			check_builtin(const char *cmd);
int			ft_cd(const char **av, char ***env);
int			ft_echo(const char **av);
int			ft_env(const char **av, char **env);
int			ft_exit(const char **av);
int			ft_hash(void);
int			ft_setenv(const char **av);
int			ft_type(const char **av);
int			ft_unsetenv(const char **av);

void		redir_reset(void);
void		redir_set(void);
int			redirect(t_io_redirect *redir);
int			redirect_error_fd(int fd);
int			redirect_error_file(char *file);
int			redirect_error_open(char *file);
int			redir_less(t_io_redirect *redir);
int			redir_dless(t_io_redirect *redir);
int			redir_tless(t_io_redirect *redir);
int			redir_great(t_io_redirect *redir, int dgreat);

#endif
