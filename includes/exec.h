/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwisoky <dwisoky@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/03 20:40:22 by dwisoky           #+#    #+#             */
/*   Updated: 2019/08/26 14:07:18 by dwisoky          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXEC_H
# define EXEC_H

# include "parser.h"
# include "lexer.h"

char		*g_tty;
int			g_res_exec;
int			*g_open_fd;

int			call_exec(const char **av, char ***env);
int			is_builtin(const char *cmd);
int			ft_cd(const char **av, char ***env);
int			ft_echo(const char **av);
int			ft_env(const char **av, char **env);
int			ft_exit(const char **av);
int			ft_hash(char **argv);
int			ft_set(const char **av);
int			ft_setenv(const char **av);
int			ft_type(const char **av);
int			ft_unset(const char **av);
int			ft_unsetenv(const char **av);
int			change_dir_with_flag(const char *dir);
int			change_dir_without_flag(const char *dir);
int			cd_error(const char *dir);
int			ft_fc(const char **av);
void		*cd_error_invalid_flag(char c);
void		redir_reset(void);
void		redir_set(void);
void		redir_add_fd_table(int fd);
int			redirect(t_io_redirect *redir);
int			redirect_error_fd(int fd);
int			redirect_error_range_fd(void);
int			redirect_error_ambiguous(char *file);
int			redirect_error_open(char *file);
int			redirect_error_dup(int fd);
int			redir_less(t_io_redirect *redir);
int			redir_dless(t_io_redirect *redir);
int			redir_tless(t_io_redirect *redir);
int			redir_less_great(t_io_redirect *redir);
int			redir_less_and(t_io_redirect *redir);
int			redir_great(t_io_redirect *redir);
int			redir_great_and(t_io_redirect *redir);
int			redir_and_great(t_io_redirect *redir);
int			redir_and_dgreat(t_io_redirect *redir);
int			redir_clobber(t_io_redirect *redir);

#endif
