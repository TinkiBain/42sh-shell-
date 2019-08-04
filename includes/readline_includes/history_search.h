/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history_search.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelisan <gmelisan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/28 17:33:38 by gmelisan          #+#    #+#             */
/*   Updated: 2019/07/30 20:08:39 by gmelisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HISTORY_SEARCH_H
# define HISTORY_SEARCH_H

# include	"ft_readline.h"

# define FAILSRCH_STR		"failing "
# define REVISRCH_STR		"bck-i-search: "

# define UNDERLINE_SEQ		"\033[4m"
# define RESET_SEQ			"\033[m"

void		hs_prepare_line(t_line *line);
void		hs_clear(t_line *line);
void		hs_find(t_line *line);
void		hs_prev(t_line *line);

#endif
