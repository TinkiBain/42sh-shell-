/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelisan </var/spool/mail/vladimir>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 21:15:38 by gmelisan          #+#    #+#             */
/*   Updated: 2019/08/19 16:38:57 by gmelisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HISTORY_H
# define HISTORY_H

# include "ft_readline.h"

/* # define HISTORY_MAXSIZE		(10 + 1) */

typedef struct	s_history
{
	t_dlist		*item;
	int			size;
	int			max_size;
	char		*path;
}				t_history;

t_history		*g_history;

void		history_load(t_history *history);
void		history_push(t_history *history, t_string str);
void		history_save(t_history *history, t_string *str);
void		history_clear(t_history *history);
t_history	*history_copy(t_history *history);

#endif
