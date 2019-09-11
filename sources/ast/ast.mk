# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ast.mk                                             :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ggwin-go <ggwin-go@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/08/05 19:44:23 by ggwin-go          #+#    #+#              #
#    Updated: 2019/09/11 20:28:06 by dwisoky          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LEXER_DIR=lexer
PARSER_DIR=parser
TRAVERSE_AST_DIR=traverse_ast
AST_REDIRECT_DIR=redirect
AST_EXPANSION_DIR=expansion

SRCS_LEXER=\
	lexer.c					lexer_check_token.c			lexer_find_dollar.c\
	print_lexem.c			lexer_check_io_number.c		lexer_free_all.c\
	lexer_find_word.c

SRCS_PARSER=\
	parser_list.c			parser_and_or.c				parser_linebreak.c\
	parser_new_line_list.c	parser_pipeline.c			parser_pipe_sequence.c\
	parser_command.c		parser_simple_command.c		parser_command_prefix.c\
	parser_io_redirect.c	parser_cmd_suffix.c			parser_io_number.c\
	parser.c				parser_compound_command.c	parser_subshell.c\
	parser_brace_group.c	parser_compound_list.c		parser_term.c\
	parser_separator.c		parser_redirect_list.c		parser_function_definition.c\
	parser_function_body.c	parser_print_error.c		parser_if_clause.c\
	parser_check_reserved_words.c						parser_else_part.c\
	parser_while_clause.c	parser_do_group.c			parser_for_clause.c\
	parser_wordlist.c		parser_sequential_sep.c		parser_case_clause.c\
	parser_case_list.c		parser_case_item.c			parser_pattern.c

SRCS_TRAVERSE_AST=\
	call_exec.c\
	check_cmd.c\
	get_cmd_name.c\
	is_builtin.c\
	push_back_av.c\
	traverse_ast.c\
	traverse_pipe.c\
	traverse_pipe_sequence.c\
	traverse_command.c\
	traverse_simple_command.c\
	traverse_redirect_list.c\
	traverse_compound_command.c\
	traverse_function_definition.c

SRCS_AST_REDIRECT=\
	redir_add_table.c\
	redir_and_dgreat.c\
	redir_and_great.c\
	redir_clobber.c\
	redir_dless.c\
	redir_great.c\
	redir_great_and.c\
	redir_less.c\
	redir_less_and.c\
	redir_less_great.c\
	redir_reset.c\
	redir_set.c\
	redir_tless.c\
	redirect.c\
	redirect_error.c

SRCS_AST_EXPANSION=\
	check_spec_symbol.c\
	dollar.c\
	tilda.c\
	tdq.c

AST_SUBDIRS=\
	$(AST_REDIRECT_DIR)\
	$(AST_EXPANSION_DIR)\
	$(LEXER_DIR)\
	$(PARSER_DIR)\
	$(PRINT_AST_DIR)\
	$(TRAVERSE_AST_DIR)

SRCS_AST=\
	$(addprefix $(LEXER_DIR)/, $(SRCS_LEXER))\
	$(addprefix $(PARSER_DIR)/, $(SRCS_PARSER))\
	$(addprefix $(TRAVERSE_AST_DIR)/, $(SRCS_TRAVERSE_AST))\
	$(addprefix $(AST_REDIRECT_DIR)/, $(SRCS_AST_REDIRECT))\
	$(addprefix $(AST_EXPANSION_DIR)/, $(SRCS_AST_EXPANSION))

