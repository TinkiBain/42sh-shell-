/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggwin-go <ggwin-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/06 16:10:45 by gmelisan          #+#    #+#             */
/*   Updated: 2019/08/15 12:00:43 by gmelisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LINE_H
# define LINE_H

# include "defs.h"
# include "history.h"

# define VI_FIND_FORWARD	1
# define VI_FIND_BACKWARD	2

typedef struct		s_line
{
	t_string		*str;			/* shortcut for history->item->content */
	t_string		oldstr;
	char			*result;		/* what we return */
	t_string		prompt;
	int				cpos;			/* relative to `str' */
	t_vector		key_bindings;
	int				arg;
	int				reading_arg;
	int				complete_fail;
	char			keybuf[KEYBUF_SIZE];
	void			(*action)(struct s_line *line);
	int				overwrite_mode;
	int				hs_mode;
	struct			s_hs
	{
		t_string	query;
		int			query_pos;
		int			success;
		t_string	original_str;
		int			original_cpos;
		t_dlist		*hist_start;
		t_dlist		*hist_current;
	}				hs;
	int				vi_mode;
	struct			s_vi
	{
		int			prev_find;
		char		prev_find_c;
	}				vi;
	t_string		kill_buffer;
	t_history		*history;
	t_history		*history_orig;
	t_list			*changes;		/* TODO: undo */
}					t_line;

t_line				*duplicate_line(t_line *line);
void				free_line(t_line *line);

#endif
