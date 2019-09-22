# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    readline.mk                                        :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ggwin-go <ggwin-go@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/08/05 14:44:06 by ggwin-go          #+#    #+#              #
#    Updated: 2019/09/22 19:16:28 by gmelisan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

READLINE_ACTIONS_DIR=actions
READLINE_COMPLETE_DIR=$(READLINE_ACTIONS_DIR)/complete
READLINE_BINDINGS_DIR=bindings
READLINE_DISPLAY_DIR=display
READLINE_TERMINAL_DIR=terminal
READLINE_INPUTLOOP_DIR=input_loop
READLINE_HISTORY_DIR=history

READLINE_INCLUDES=\
	actions.h			bindings.h		display.h		escseqs.h\
	ft_readline.h		history.h		history_search.h\
	input_loop.h		keys.h			line.h			loginfo.h\
	signal_handlers.h	terminal.h		utils.h			undo.h\
	colors.h			del_funcs.h

SRCS_READLINE_WITHOUT_DIR=\
	ft_readline.c\
	loginfo.c			signal_handlers.c	utils.c		del_funcs.c\
	duplicate_line.c	undo.c				gnl.c

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
	vi_delete_to_motion.c	vi_delete_to_end.c		vi_clear_line.c\
	vi_comment.c			vi_vi.c					vi_goto_char.c\
	vi_forward_word.c		vi_backward_word.c		vi_ignore.c\
	vi_forward_bigword.c	vi_backward_bigword.c	vi_replace.c\
	vi_forward_word_start.c vi_forward_bigword_start.c\
	vi_find_forward.c		vi_find_backward.c		vi_repeat_find.c\
	vi_repeat_find_reverse.c						vi_delete_to_motion_save.c\
	vi_delete_to_end_save.c	vi_paste_after.c		vi_paste_before.c\
	vi_yank_to_motion.c		vi_yank_to_end.c		undo.c\
	undo_all.c

SRCS_READLINE_COMPLETE=\
	filter_filenames.c		filter_variables.c	filter_commands.c\
	show_completions.c		complete.c			filter_command_options.c\
	possible_filename_completions.c				complete_filename.c\
	possible_command_completions.c				complete_command.c\
												complete_command_option.c\
	possible_variable_completions.c				complete_variable.c\
	find_common_part.c

SRCS_READLINE_TERMINAL=\
	terminal.c				term_fillcap.c\

SRCS_READLINE_BINDINGS=\
	bind.c		bind_keys.c		bindings.c		vi_bind_keys.c	is_vi_motion.c

SRCS_READLINE_DISPLAY=\
	clear_linebuf.c			init_linebuf.c		move_cursor.c\
	redisplay.c				update_line.c		escseqs.c\
	escseq_test_unmatch.c	get_screen_sizes.c	colorize.c\

SRCS_READLINE_INPUTLOOP=\
	em_input_loop.c		input_loop.c	is_ansiseq.c	vi_input_loop.c\
	vi_input_one.c

SRCS_READLINE_HISTORY=\
	go_history.c	history_clear.c		history_copy.c		history_load.c\
	history_push.c	history_save.c		history_expand.c\
	history_search.c					history_search_clear.c

READLINE_SUBDIRS=\
	$(READLINE_ACTIONS_DIR)\
	$(READLINE_BINDINGS_DIR)\
	$(READLINE_DISPLAY_DIR)\
	$(READLINE_COMPLETE_DIR)\
	$(READLINE_TERMINAL_DIR)\
	$(READLINE_INPUTLOOP_DIR)\
	$(READLINE_HISTORY_DIR)\

SRCS_READLINE=$(SRCS_READLINE_WITHOUT_DIR)\
	$(addprefix $(READLINE_ACTIONS_DIR)/, $(SRCS_READLINE_ACTIONS))\
	$(addprefix $(READLINE_BINDINGS_DIR)/, $(SRCS_READLINE_BINDINGS))\
	$(addprefix $(READLINE_DISPLAY_DIR)/, $(SRCS_READLINE_DISPLAY))\
	$(addprefix $(READLINE_COMPLETE_DIR)/, $(SRCS_READLINE_COMPLETE))\
	$(addprefix $(READLINE_TERMINAL_DIR)/, $(SRCS_READLINE_TERMINAL))\
	$(addprefix $(READLINE_INPUTLOOP_DIR)/, $(SRCS_READLINE_INPUTLOOP))\
	$(addprefix $(READLINE_HISTORY_DIR)/, $(SRCS_READLINE_HISTORY))\
