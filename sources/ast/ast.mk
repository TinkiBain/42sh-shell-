# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ast.mk                                             :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jterry <jterry@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/08/05 19:44:23 by ggwin-go          #+#    #+#              #
#    Updated: 2019/10/25 16:39:54 by jterry           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LEXER_DIR=lexer

SRCS_LEXER=\
	lexer.c							lexer_check_bracket.c\
	lexer_check_io_number.c			lexer_check_token.c\
	lexer_find_dollar.c				lexer_find_word.c\
	lexer_free_all.c

PARSER_DIR=parser

SRCS_PARSER=\
	parser.c						parser_and_or.c\
	parser_brace_group.c			parser_case_clause.c\
	parser_case_item.c				parser_case_list.c\
	parser_check_alias.c			parser_check_reserved_words.c\
	parser_check_word.c				parser_cmd_suffix.c\
	parser_command.c				parser_command_prefix.c\
	parser_compound_command.c		parser_compound_list.c\
	parser_do_group.c				parser_else_part.c\
	parser_find_eq.c				parser_fname.c\
	parser_for_clause.c				parser_free_ast.c\
	parser_function_body.c			parser_function_definition.c\
	parser_if_clause.c				parser_io_number.c\
	parser_io_redirect.c			parser_linebreak.c\
	parser_list.c					parser_new_line_list.c\
	parser_pattern.c				parser_pipe_sequence.c\
	parser_pipeline.c				parser_print_error.c\
	parser_recall_readline.c		parser_redirect_list.c\
	parser_separator.c				parser_sequential_sep.c\
	parser_simple_command.c			parser_subshell.c\
	parser_term.c					parser_while_clause.c\
	parser_word_expansion.c			parser_wordlist.c

TRAVERSE_AST_DIR=traverse_ast

SRCS_TRAVERSE_AST=\
	call_exec.c						call_subshell.c\
	check_cmd.c						check_name.c\
	get_job_name.c					get_process_name.c\
	is_builtin.c					traverse_ast.c\
	traverse_case_clause.c			traverse_command.c\
	traverse_compound_command.c		traverse_compound_list.c\
	traverse_for_clause.c			traverse_function_definition.c\
	traverse_if_clause.c			traverse_pipe.c\
	traverse_pipe_sequence.c		traverse_redirect_list.c\
	traverse_simple_command.c		traverse_until_clause.c\
	traverse_while_clause.c

AST_REDIRECT_DIR=redirect

SRCS_AST_REDIRECT=\
	redir_add_table.c				redir_and_dgreat.c\
	redir_and_great.c				redir_clobber.c\
	redir_dless.c					redir_great.c\
	redir_great_and.c				redir_less.c\
	redir_less_and.c				redir_less_great.c\
	redir_reset.c					redir_set.c\
	redir_tless.c					redirect.c\
	redirect_error.c

AST_EXPANSION_DIR=expansion

SRCS_AST_EXPANSION=\
	arithmetic.c						arithmetic_lexer.c\
	arithmetic_lexer_check_token.c	arithmetic_lexer_digit.c\
	arithmetic_lexer_logical_op.c	arithmetic_lexer_simple_operations.c\
	arithmetic_lexer_var.c			arithmetic_error.c\
	back_bigest_eq.c				back_smaller_eq.c\
	check_spec_symbol.c				dollar.c\
	dollar_brace.c					dollar_brace_forward.c\
	dollar_double_dote.c			dollar_handler_plus.c\
	expr.c							expr_additive.c\
	expr_and.c						expr_bracket.c\
	expr_check_var.c				expr_equal.c\
	expr_exclusive_or.c				expr_get_var_value.c\
	expr_logic_and.c				expr_logic_or.c\
	expr_multiplicativ.c			expr_or.c\
	expr_prefix.c					expr_relat_op.c\
	expr_return_value.c				expr_shift.c\
	expr_suffix.c					expr_unar.c\
	forward_bigest_eq.c				forward_smaller_eq.c\
	substitution.c					tdq.c\
	tdq_cleaner.c					tilda.c

SRCS_AST_WITHOUT_DIR=\
	alias_func_size.c				create_arr_names.c\
	get_lexem_value.c				fill_hash_table.c

AST_SUBDIRS=\
	$(AST_REDIRECT_DIR)\
	$(AST_EXPANSION_DIR)\
	$(LEXER_DIR)\
	$(PARSER_DIR)\
	$(PRINT_AST_DIR)\
	$(TRAVERSE_AST_DIR)

SRCS_AST=$(SRCS_AST_WITHOUT_DIR)\
	$(addprefix $(LEXER_DIR)/, $(SRCS_LEXER))\
	$(addprefix $(PARSER_DIR)/, $(SRCS_PARSER))\
	$(addprefix $(TRAVERSE_AST_DIR)/, $(SRCS_TRAVERSE_AST))\
	$(addprefix $(AST_REDIRECT_DIR)/, $(SRCS_AST_REDIRECT))\
	$(addprefix $(AST_EXPANSION_DIR)/, $(SRCS_AST_EXPANSION))

