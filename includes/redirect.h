/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggwin-go <ggwin-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 19:29:37 by ggwin-go          #+#    #+#             */
/*   Updated: 2019/09/10 19:30:30 by ggwin-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REDIRECT_H
# define REDIRECT_H

# include "parser.h"

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
