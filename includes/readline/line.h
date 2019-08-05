/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggwin-go <ggwin-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/06 16:10:45 by gmelisan          #+#    #+#             */
/*   Updated: 2019/08/05 16:53:09 by gmelisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LINE_H
# define LINE_H

# include "defs.h"
# include "history.h"

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
	char			keybuf[KEYBUF_SIZE];
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
	int				vi_mode;	/* TODO: vi */
	t_string		kill_buffer;
	t_history		*history;
	t_history		*history_orig;
	t_list			*changes;		/* TODO: undo */
}					t_line;

#endif
