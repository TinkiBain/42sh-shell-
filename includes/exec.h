/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggwin-go <ggwin-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/03 20:40:22 by dwisoky           #+#    #+#             */
/*   Updated: 2019/08/06 21:22:20 by dwisoky          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXEC_H
# define EXEC_H

#include "parser.h"
#include "lexer.h"

int			g_res_exec;
int			g_fd[3];

int			call_exec(char **av, char ***env);
int			check_builtin(char *cmd);
int			ft_cd(char **av);
int			ft_echo(char **av);
int			ft_env(char **av, char **env);
int			ft_exit(char **av);
int			ft_hash(void);
int			ft_setenv(char **av);
void		ft_type(char **av);
int			ft_unsetenv(char **av);

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
