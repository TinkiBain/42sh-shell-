/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jterry <jterry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/13 20:32:07 by dwisoky           #+#    #+#             */
/*   Updated: 2019/10/07 20:22:54 by jterry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include <sys/wait.h>
# include "lexer.h"

int							g_end_parsing;
int							g_parser_case_list_end;
t_lex						*g_lex;
t_lex						*g_error_lex;

typedef struct		s_io_redirect
{
	char				*file_name;
	int					type;
	int					io_number;
}					t_io_redirect;

typedef struct		s_cmd_suffix
{
	struct s_cmd_suffix	*cmd_suf;
	t_io_redirect		*io_redir;
	char				*word;
}					t_cmd_suffix;

typedef struct		s_cmd_prefix
{
	struct s_cmd_prefix	*cmd_pref;
	t_io_redirect		*io_redir;
	char				*assignment_word;
}					t_cmd_prefix;

typedef struct		s_simple_cmd
{
	t_cmd_prefix		*cmd_pref;
	t_cmd_suffix		*cmd_suf;
	t_lex				*lex_begin;
	t_lex				*lex_end;
	char				*cmd_name;
}					t_simple_cmd;

typedef struct		s_term
{
	struct s_term		*next;
	struct s_and_or		*and_or;
	int					separator;
}					t_term;

typedef struct		s_compound_list
{
	t_term				*term;
	struct s_and_or		*and_or;
	t_lex				*lex_begin;
	t_lex				*lex_end;
	int					separator;
}					t_compound_list;

typedef struct		s_else_part
{
	t_compound_list		*head_compound;
	t_compound_list		*compound_list;
	struct s_else_part	*next_else_part;
}					t_else_part;

typedef struct		s_if_clause
{
	t_compound_list		*if_head;
	t_compound_list		*if_body;
	t_else_part			*else_part;
}					t_if_clause;

typedef struct		s_while_clause
{
	t_compound_list		*compound_list;
	t_compound_list		*do_group;
}					t_while_clause;

typedef struct		s_wordlist
{
	struct s_wordlist	*next;
	char				*word;
}					t_wordlist;

typedef struct		s_for_clause
{
	t_compound_list		*do_group;
	t_wordlist			*wordlist;
	char				*name;
}					t_for_clause;

typedef struct		s_pattern
{
	struct s_pattern	*next_pattern;
	char				*word;
}					t_pattern;

typedef struct		s_case_item
{
	t_compound_list		*compound_list;
	t_pattern			*pattern;
}					t_case_item;

typedef struct		s_case_list
{
	struct s_case_list	*next;
	t_case_item			*case_item;
}					t_case_list;

typedef struct		s_case_clause
{
	t_case_list			*case_list;
	char				*word;
}					t_case_clause;

typedef struct		s_compound_cmd
{
	t_compound_list		*compound_list;
	t_if_clause			*if_clause;
	t_for_clause		*for_clause;
	t_while_clause		*while_clause;
	t_while_clause		*until_clause;
	t_case_clause		*case_clause;
	t_lex				*begin_lex;
	t_lex				*end_lex;
}					t_compound_cmd;

typedef struct		s_command
{
	struct s_simple_cmd			*simple_command;
	struct s_compound_cmd		*compound_command;
	struct s_redirect_list		*redirect_list;
	struct s_func_definition	*function_definition;
}					t_command;

typedef struct		s_func_definition
{
	struct s_function_body	*function_body;
	char					*function_name;
}					t_func_definition;

typedef struct		s_function_body
{
	t_compound_cmd			*compound_command;
	struct s_redirect_list	*redirect_list;
}					t_function_body;

typedef struct		s_redirect_list
{
	struct s_redirect_list	*next;
	t_io_redirect			*io_redirect;
	t_lex					*end_lex;
}					t_redirect_list;

typedef struct		s_pipe_sequence
{
	t_command				*command;
	struct s_pipe_sequence	*next;
	int						pipe_op;
}					t_pipe_sequence;

typedef struct		s_pipeline
{
	t_pipe_sequence			*pipe_sequence;
	int						bang;
}					t_pipeline;

typedef struct		s_and_or
{
	struct s_and_or			*next;
	t_pipeline				*pipeline;
	int						and_or_if;
}					t_and_or;

typedef struct		s_pars_list
{
	struct s_pars_list		*next;
	t_and_or				*and_or;
	t_lex					*lex_begin;
	t_lex					*lex_end;
	int						sep;
}					t_pars_list;

typedef struct		s_complete_cmd
{
	t_pars_list				*list;
	int						sep;
}					t_complete_cmd;

t_complete_cmd		*parser(void);
t_complete_cmd		*parser_free(t_complete_cmd *list);
t_pars_list			*parser_list(t_pars_list *list_down);
t_pars_list			*parser_free_list(t_pars_list *list);
t_and_or			*parser_and_or(t_and_or *list_down);
t_and_or			*parser_free_and_or(t_and_or *list);
t_pipeline			*parser_pipeline(void);
t_pipeline			*parser_free_pipeline(t_pipeline *list);
t_pipe_sequence		*parser_pipe_sequence(void);
t_pipe_sequence		*parser_free_pipe_sequence(t_pipe_sequence *list);
t_command			*parser_command(void);
t_command			*parser_free_command(t_command *list);
t_compound_cmd		*parser_compound_command(void);
t_compound_cmd		*parser_free_compound_command(t_compound_cmd *list);
t_redirect_list		*parser_redirect_list(t_redirect_list *list_down);
t_redirect_list		*parser_free_redirect_list(t_redirect_list *list);
t_compound_list		*parser_subshell(void);
t_compound_list		*parser_brace_group(void);
t_compound_list		*parser_compound_list(void);
t_compound_list		*parser_free_compound_list(t_compound_list *list);
t_term				*parser_term(t_term *list_down);
t_term				*parser_free_term(t_term *list);
t_func_definition	*parser_function_definition(void);
t_func_definition	*parser_free_function_definition(t_func_definition *list);
t_function_body		*parser_function_body(void);
t_function_body		*parser_free_function_body(t_function_body *list);
t_if_clause			*parser_if_clause(void);
t_if_clause			*parser_free_if_clause(t_if_clause *list);
t_for_clause		*parser_for_clause(void);
t_for_clause		*parser_free_for_clause(t_for_clause *list);
t_else_part			*parser_else_part(void);
t_else_part			*parser_free_else_part(t_else_part *list);
t_while_clause		*parser_while_clause(void);
t_case_clause		*parser_case_clause(void);
t_case_clause		*parser_free_case_clause(t_case_clause *list);
t_case_list			*parser_case_list(void);
t_case_list			*parser_free_case_list(t_case_list *list);
t_case_item			*parser_case_item(void);
t_case_item			*parser_free_case_item(t_case_item *list);
t_pattern			*parser_pattern(void);
t_pattern			*parser_free_pattern(t_pattern *list);
t_while_clause		*parser_free_while_clause(t_while_clause *list);
t_compound_list		*parser_do_group(void);
t_wordlist			*parser_wordlist(void);
t_wordlist			*parser_free_wordlist(t_wordlist *list);
t_simple_cmd		*parser_simple_command(void);
t_simple_cmd		*parser_free_simple_command(t_simple_cmd *list);
t_io_redirect		*parser_io_redirect(void);
t_io_redirect		*parser_free_io_redirect(t_io_redirect *list);
t_cmd_prefix		*parser_cmd_prefix(void);
t_cmd_prefix		*parser_free_cmd_prefix(t_cmd_prefix *list);
t_cmd_suffix		*parser_cmd_suffix(void);
t_cmd_suffix		*parser_free_cmd_suffix(t_cmd_suffix *list);
char				*parser_check_alias(char *str);
char				*parser_call_back_readline(int lex_or);
char				*parser_recall_readline(char c);
char				*parser_name(void);
char				*parser_fname(void);
char				*parser_expansion_subshell(char *str, char **new_str);
char				*parser_word_expansion(char *str);
int					parser_find_eq(void);
int					parser_sequential_sep(void);
int					parser_io_number(void);
int					parser_separator(void);
int					parser_check_reserved_words(void);
int					parser_find_eq(void);
void				parser_linebreak(void);
void				parser_new_line_list(void);
void				parser_print_error(void);
char				*parser_find_dollar(char *str);

#endif
