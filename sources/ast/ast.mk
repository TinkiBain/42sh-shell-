# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ast.mk                                             :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ggwin-go <ggwin-go@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/08/05 19:44:23 by ggwin-go          #+#    #+#              #
#    Updated: 2019/08/05 21:47:22 by ggwin-go         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LEXER_DIR=lexer
PARSER_DIR=parser
TRAVERSE_AST_DIR=traverse_ast
PRINT_AST_DIR=print_ast

SRCS_LEXER=\
	lexer.c					lexer_and_or.c			lexer_check_redir.c\
	lexer_get_token.c		lexer_bang.c

SRCS_PARSER=\
	parser.c				parser_and_or.c			parser_cmd.c\
	parser_cmd_prefix.c		parser_cmd_suffix.c		parser_io_redirect.c\
	parser_pipe_sequence.c	parser_pipeline.c		parser_print_error.c\
	parser_free_tree.c		parser_free_cmd.c

SRCS_TRAVERSE_AST=\
	handle_token_assignment_word.c\
	push_back_av.c\
	traverse_ast.c\
	traverse_cmd.c\
	traverse_io_redir.c\
	traverse_pipeline.c

SRCS_PRINT_AST=\
	print_ast.c

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
