# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ast.mk                                             :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ggwin-go <ggwin-go@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/08/05 19:44:23 by ggwin-go          #+#    #+#              #
#    Updated: 2019/09/08 16:47:24 by dwisoky          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LEXER_DIR=lexer
PARSER_DIR=parser
TRAVERSE_AST_DIR=traverse_ast

SRCS_LEXER=\
	lexer.c					lexer_check_token.c			lexer_check_reserved_word.c\
	print_lexem.c			lexer_check_io_number.c		lexer_free_all.c\
	lexer_find_word.c		lexer_find_dollar.c

SRCS_PARSER=\
	parser_list.c			parser_and_or.c				parser_linebreak.c\
	parser_new_line_list.c	parser_pipeline.c			parser_pipe_sequence.c\
	parser_command.c		parser_simple_command.c		parser_command_prefix.c\
	parser_io_redirect.c	parser_cmd_suffix.c			parser_io_number.c\
	parser.c				parser_compound_command.c	parser_subshell.c\
	parser_brace_group.c	parser_compound_list.c		parser_term.c\
	parser_separator.c		parser_redirect_list.c		parser_function_definition.c\
	parser_function_body.c

SRCS_TRAVERSE_AST=\
	traverse_ast.c\
	traverse_pipe_sequence.c\
	is_builtin.c\
	push_back_av.c\
	redirect.c\
	redir_set.c\
	redir_reset.c\
	redir_add_table.c\
	redirect_error.c\
	redir_less.c\
	redir_dless.c\
	redir_tless.c\
	redir_less_great.c\
	redir_less_and.c\
	redir_great.c\
	redir_great_and.c\
	redir_and_great.c\
	redir_and_dgreat.c\
	redir_clobber.c\
	tilda.c\
	dollar.c\
	call_exec.c\
	check_spec_symbol.c\
	check_cmd.c\
	handle_token_assignment_word.c\
	traverse_cmd.c\
	tdq.c

AST_SUBDIRS=\
	$(LEXER_DIR)\
	$(PARSER_DIR)\
	$(TRAVERSE_AST_DIR)\
	$(PRINT_AST_DIR)

SRCS_AST=\
	$(addprefix $(LEXER_DIR)/, $(SRCS_LEXER))\
	$(addprefix $(PARSER_DIR)/, $(SRCS_PARSER))\
	$(addprefix $(TRAVERSE_AST_DIR)/, $(SRCS_TRAVERSE_AST))\
