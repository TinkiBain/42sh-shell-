# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ast.mk                                             :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ggwin-go <ggwin-go@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/08/05 19:44:23 by ggwin-go          #+#    #+#              #
#    Updated: 2019/08/25 19:08:41 by ggwin-go         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LEXER_DIR=lexer
PARSER_DIR=parser
TRAVERSE_AST_DIR=traverse_ast
PRINT_AST_DIR=print_ast

SRCS_LEXER=\
	lexer.c					lexer_and_or.c			lexer_check_redir.c\
	lexer_get_token.c		lexer_bang.c			lexer_free_all.c

SRCS_PARSER=\
	parser.c				parser_and_or.c			parser_cmd.c\
	parser_cmd_prefix.c		parser_cmd_suffix.c		parser_io_redirect.c\
	parser_pipe_sequence.c	parser_pipeline.c		parser_print_error.c\
	parser_free_tree.c		parser_free_cmd.c

SRCS_TRAVERSE_AST=\
	call_exec.c\
	check_builtin.c\
	check_cmd.c\
	handle_token_assignment_word.c\
	push_back_av.c\
	traverse_ast.c\
	traverse_cmd.c\
	print_error.c\
	redirect.c\
	traverse_pipeline.c\
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
	check_spec_symbol.c\
	tdq.c

SRCS_PRINT_AST=\
	print_ast.c				print_ast_cmd.c\
	print_ast_io_redir.c	print_ast_token_number.c\
	print_ast_token_word.c	print_ast_token_assignment_word.c

AST_SUBDIRS=\
	$(LEXER_DIR)\
	$(PARSER_DIR)\
	$(TRAVERSE_AST_DIR)\
	$(PRINT_AST_DIR)

SRCS_AST=\
	$(addprefix $(LEXER_DIR)/, $(SRCS_LEXER))\
	$(addprefix $(PARSER_DIR)/, $(SRCS_PARSER))\
	$(addprefix $(TRAVERSE_AST_DIR)/, $(SRCS_TRAVERSE_AST))\
	$(addprefix $(PRINT_AST_DIR)/, $(SRCS_PRINT_AST))
