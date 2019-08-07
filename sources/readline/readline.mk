# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    readline.mk                                        :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ggwin-go <ggwin-go@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/08/05 14:44:06 by ggwin-go          #+#    #+#              #
#    Updated: 2019/08/07 22:13:10 by gmelisan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

READLINE_ACTIONS_DIR=actions
READLINE_COMPLETE_DIR=$(READLINE_ACTIONS_DIR)/complete
READLINE_BINDINGS_DIR=bindings
READLINE_DISPLAY_DIR=display

SRCS_READLINE_WITHOUT_DIR=\
	escseqs.c			ft_errno.c		ft_readline.c		history.c\
	history_search.c	input_loop.c	loginfo.c			signal_handlers.c\
	str_xfuncs1.c		str_xfuncs2.c	terminal.c			vec_xfuncs.c\
	vi_input_loop.c		xmalloc.c

SRCS_READLINE_ACTIONS=\
	backward_char.c			backward_delete_char.c	backward_line.c\
	backward_word.c			beginning_of_line.c		clear_screen.c\
	delete_char.c			end_of_line.c			forward_char.c\
	forward_line.c			forward_word.c			kill_line.c\
	next_history.c			overwrite_mode.c		previous_history.c\
	reset_history_search.c	reset_line.c			reverse_search_history.c\
	self_insert.c			transpose_chars.c		transpose_words.c\
	unix_line_discard.c		unix_word_rubout.c		yank.c\
	vi_command.c			vi_insert_at.c			vi_insert_after.c\
	vi_insert_beginning.c	vi_insert_end.c			vi_insert_overwrite.c\
	vi_beginning_of_line_nonblank.c					transpose_words_supp.c\

SRCS_READLINE_COMPLETE=\
	get_filenames.c			show_completions.c		complete_filename.c\
	possible_filename_complitions.c

SRCS_READLINE_BINDINGS=\
	bind.c		bind_keys.c		bindings.c		vi_bind_keys.c

SRCS_READLINE_DISPLAY=\
	clear_linebuf.c	init_linebuf.c	move_cursor.c	redisplay.c	update_line.c

READLINE_SUBDIRS=\
	$(READLINE_ACTIONS_DIR)\
	$(READLINE_BINDINGS_DIR)\
	$(READLINE_DISPLAY_DIR)\
	$(READLINE_COMPLETE_DIR)

SRCS_READLINE=$(SRCS_READLINE_WITHOUT_DIR)\
	$(addprefix $(READLINE_ACTIONS_DIR)/, $(SRCS_READLINE_ACTIONS))\
	$(addprefix $(READLINE_BINDINGS_DIR)/, $(SRCS_READLINE_BINDINGS))\
	$(addprefix $(READLINE_DISPLAY_DIR)/, $(SRCS_READLINE_DISPLAY))\
	$(addprefix $(READLINE_COMPLETE_DIR)/, $(SRCS_READLINE_COMPLETE))
