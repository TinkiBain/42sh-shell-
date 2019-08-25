/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_handlers.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggwin-go <ggwin-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/05 21:58:25 by gmelisan          #+#    #+#             */
/*   Updated: 2019/08/25 13:57:11 by ggwin-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SIGNAL_HANDLERS_H
# define SIGNAL_HANDLERS_H

# include "ft_readline.h"

void	sigh_sigsegv(int sig);
void	sigh_sigabrt(int sig);
void	sigh_sigint(int sig);
void	sigh_sigwinch(int sig);
void	sigh_sigterm(int sig);
void	sigh_ignore(int sig);

extern int		g_logfd;
extern t_line	*g_line;

#endif
