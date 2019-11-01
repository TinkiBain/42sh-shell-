/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwisoky <dwisoky@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 19:29:37 by dwisoky           #+#    #+#             */
/*   Updated: 2019/11/02 01:24:59 by dwisoky          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REDIRECT_H
# define REDIRECT_H

# include "parser.h"
# include "jobs.h"

void		redir_reset(void);
void		redir_set(void);
void		redir_add_fd_table(int fd);
int			redirect(t_io_redirect *redir, t_pjobs **local);
int			redirect_error_fd(int fd);
int			redirect_error_range_fd(void);
int			redirect_error_ambiguous(char *file);
int			redirect_error_open(char *file);
int			redirect_error_dup(int fd);
int			redir_less(t_io_redirect *redir);
int			redir_dless(t_io_redirect *redir, t_pjobs **local);
int			redir_tless(t_io_redirect *redir);
int			redir_less_great(t_io_redirect *redir);
int			redir_less_and(t_io_redirect *redir);
int			redir_great(t_io_redirect *redir);
int			redir_great_and(t_io_redirect *redir);
int			redir_and_great(t_io_redirect *redir);
int			redir_and_dgreat(t_io_redirect *redir);
int			redir_clobber(t_io_redirect *redir);

#endif
