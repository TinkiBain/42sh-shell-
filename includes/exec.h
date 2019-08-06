/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggwin-go <ggwin-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/03 20:40:22 by dwisoky           #+#    #+#             */
/*   Updated: 2019/08/06 17:58:21 by ggwin-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXEC_H
# define EXEC_H

int			g_res_exec;

int			check_builtin(char *cmd);
int			ft_cd(char **av);
int			ft_echo(char **av);
int			ft_env(char **av, char **env);
int			ft_exit(char **av);
int			ft_hash(void);
int			ft_setenv(char **av);
void		ft_type(char **av);
int			ft_unsetenv(char **av);

// int			exec_fill_fifo(t_attr *attr, int fd);
// void		return_fd(int fd[3]);
// int			*set_fd(void);
// int			exec_print_error(char *str);
// int			exec_redir_right(t_attr *cmd);


// int			exec_open(int fd, char *file);

#endif
