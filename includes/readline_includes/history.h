/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelisan </var/spool/mail/vladimir>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 21:15:38 by gmelisan          #+#    #+#             */
/*   Updated: 2019/07/28 17:34:25 by gmelisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HISTORY_H
# define HISTORY_H

# include "ft_readline.h"

# define HISTORY_MAXSIZE		11			/* 10 history + 1 actual */
# define DEFAULT_HIST_PATH		"./.42sh.history"

typedef struct	s_history
{
	t_dlist		*item;
	int			size;
	char		*path;
}				t_history;

void		history_load(t_history *history, char *path);
void		history_push(t_history *history, t_string str);
void		history_save(t_history *history, t_string *str);
void		history_clear(t_history *history);
t_history	*history_copy(t_history *history);

#endif
