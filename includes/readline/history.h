/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggwin-go <ggwin-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 21:15:38 by gmelisan          #+#    #+#             */
/*   Updated: 2019/08/25 17:24:11 by gmelisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HISTORY_H
# define HISTORY_H

# include "ft_readline.h"

/*
**# define HISTORY_MAXSIZE		(10 + 1)
*/

t_history		*g_history;

void		history_load(t_history *history);
void		history_push(t_history *history, t_string str);
void		history_save(t_history *history, t_string *str);
void		history_clear(t_history *history);
t_history	*history_copy(t_history *history);
void		history_expand(t_line *line);
void		del_hist(void *content, size_t size);

int			next_history_check(t_line *line);
int			previous_history_check(t_line *line);
int			len_history(t_line *line);

#endif
