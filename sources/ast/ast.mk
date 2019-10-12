# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ast.mk                                             :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dwisoky <dwisoky@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/08/05 19:44:23 by ggwin-go          #+#    #+#              #
#    Updated: 2019/10/12 20:58:57 by dwisoky          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LEXER_DIR=lexer
PARSER_DIR=parser
TRAVERSE_AST_DIR=traverse_ast
AST_REDIRECT_DIR=redirect
AST_EXPANSION_DIR=expansion

SRCS_LEXER=\
	lexer.c					lexer_check_token.c			lexer_find_dollar.c\
	lexer_check_bracket.c	lexer_check_io_number.c		lexer_free_all.c\
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
	parser_case_list.c		parser_case_item.c			parser_pattern.c\
	parser_check_alias.c	parser_find_eq.c			parser_fname.c\
	parser_word_expansion.c	parser_recall_readline.c

SRCS_TRAVERSE_AST=\
	call_exec.c\
	call_subshell.c\
	check_cmd.c\
	check_name.c\
	get_job_name.c\
	get_process_name.c\
	is_builtin.c\
	traverse_ast.c\
	traverse_pipe.c\
	traverse_pipe_sequence.c\
	traverse_command.c\
	traverse_simple_command.c\
	traverse_redirect_list.c\
	traverse_redirections.c\
	traverse_compound_command.c\
	traverse_compound_list.c\
	traverse_function_definition.c\
	traverse_if_clause.c\
	traverse_while_clause.c\
	traverse_until_clause.c\
	traverse_for_clause.c\
	traverse_case_clause.c

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
	tdq.c\
	tdq_cleaner.c\
	dollar_brace.c\
	dollar_handler_plus.c\
	back_bigest_eq.c\
	back_smaller_eq.c\
	forward_smaller_eq.c\
	forward_bigest_eq.c\
	arifmetic.c\
	arifmetic_lexer.c\
	arifmetic_lexer_var.c\
	arifmetic_lexer_digit.c\
	arifmetic_lexer_check_token.c\
	arifmetic_lexer_simple_operations.c\
	arifmetic_lexer_logical_op.c\
	expr.c\
	expr_or.c\
	expr_and.c\
	expr_logic_or.c\
	expr_exclusive_or.c\
	expr_logic_and.c\
	expr_equal.c\
	expr_relat_op.c\
	expr_shift.c\
	expr_multiplicativ.c\
	expr_additive.c\
	expr_suffix.c\
	expr_prefix.c\
	expr_unar.c\
	expr_get_var_value.c\
	expr_return_value.c\
	expr_bracket.c\
	substitution.c\
	dollar_brace_forward.c\
	dollar_double_dote.c\
	arithmetic_error.c

SRCS_AST_WITHOUT_DIR=\
	get_lexem_value.c\
	alias_func_size.c\
	fill_hash_table.c\
	create_arr_names.c

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

