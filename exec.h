/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggwin-go <ggwin-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/03 20:40:22 by dwisoky           #+#    #+#             */
/*   Updated: 2019/06/10 20:24:57 by ggwin-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXEC_H
# define EXEC_H

# include "sh.h"
# include "libft.h"
# include <fcntl.h>
# include <stdio.h>

int			exec_fill_fifo(t_attr *attr, int fd);
void		return_fd(int fd[3]);
void		set_fd(int fd[3]);
int			exec_print_error(char *str);
int			exec_redir_right(t_attr *cmd);


int			exec_open(int fd, char *file);

#endif
