/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jterry <jterry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/06 16:10:45 by gmelisan          #+#    #+#             */
/*   Updated: 2019/10/25 16:33:03 by jterry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LINE_H
# define LINE_H

# define VI_FIND_FORWARD	1
# define VI_FIND_BACKWARD	2

# include "defs.h"

typedef struct		s_history
{
	t_dlist			*item;
	int				size;
	int				max_size;
	char			*path;
	int				start_index;
}					t_history;

/*
** mode - defines history behavior (save, not save, concat)
** str - actual line, link to last item of history
** result - what will return from ft_readline()
** prompt - what will be shown before line
** cpos - cursor position
** key_bindings - array of <t_binding>
** arg - argument to command, digit in vi_mode, esc-digit in emacs_mode
** reading_arg - flag to determine if we in reading argument state
** complete_fail - now not in use, supposed to be used in completion logic
** keybuf - buffer with what was readed from keyboard
** action - pointer to actual command to be execute
** overwrite_mode - flag to know if inserting chars should overwrite
** hs_mode - flag for history search mode
** hs - struct with data for history search
** emacs_mode - emacs mode flag
** vi_mode - 0, VI_INSERT, VI_COMMAND - value of actual vi mode
** vi - struct with data for vi mode
** kill_buffer - for copy-pasting
** history_orig - link to original history, changes only at return
** history - copy of history_orig with local changes (not for saving)
** undo - list of <t_undo_item>
**
** duplicate_line() - creates new line, allocates only new str
** free_line() - frees what duplicate_line() returned
*/

typedef struct		s_line
{
	enum e_rl_mode	mode;
	t_string		*str;
	t_string		result;
	t_string		prompt;
	int				cpos;
	t_vector		key_bindings;
	int				arg;
	int				reading_arg;
	int				complete_fail;
	t_string		keybuf;
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
	t_uint			emacs_mode;
	t_uint			vi_mode;
	struct			s_vi
	{
		int			prev_find;
		char		prev_find_c;
	}				vi;
	t_string		kill_buffer;
	t_history		*history_orig;
	t_history		*history;
	t_list			*undo;
}					t_line;

t_line				*duplicate_line(t_line *line);
void				free_line(t_line *line);

#endif
