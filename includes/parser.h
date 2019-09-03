/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggwin-go <ggwin-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/13 20:32:07 by dwisoky           #+#    #+#             */
/*   Updated: 2019/08/24 20:33:34 by ggwin-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "lexer.h"

int						g_error_pars;
t_lex					*g_lex;
t_lex					*g_error_lex;

typedef struct			s_io_redirect
{
	char				*file_name;
	int					type;
	int					io_number;
}						t_io_redirect;

typedef struct			s_cmd_suffix
{
	struct s_cmd_suffix	*cmd_suf;
	t_io_redirect		*io_redir;
	char				*word;
}						t_cmd_suffix;

typedef struct			s_cmd_prefix
{
	struct s_cmd_prefix	*cmd_pref;
	t_io_redirect		*io_redir;
	char				*assignment_word;
}						t_cmd_prefix;

typedef struct			s_cmd
{
	t_cmd_prefix		*cmd_pref;
	t_cmd_suffix		*cmd_suf;
	char				*cmd_word;
	char				*cmd_name;
}						t_cmd;

typedef struct			s_pipe_sequence
{
	t_cmd					*cmd;
	struct s_pipe_sequence	*next;
}						t_pipe_sequence;

typedef struct			s_pipeline
{
	t_pipe_sequence		*pipe_sequence;
	int					bang;
}						t_pipeline;

typedef struct			s_and_or
{
	struct s_and_or		*and_or;
	t_pipeline			*pipeline;
	int					and_or_if;
}						t_and_or;

typedef struct			s_pars_list
{
	struct s_pars_list	*list;
	t_and_or			*and_or;
	int					sep;
}						t_pars_list;

t_pars_list				*parser(t_pars_list *list_down);
t_pars_list				*parser_free_list(t_pars_list *list);
t_and_or				*parser_and_or(t_and_or *list_down);
t_and_or				*parser_free_and_or(t_and_or *list);
t_pipeline				*parser_pipeline(void);
t_pipeline				*parser_free_pipeline(t_pipeline *list);
t_pipe_sequence			*parser_pipe_sequence(t_pipe_sequence *list_down);
t_pipe_sequence			*parser_free_pipe_sequence(t_pipe_sequence *list);

void					parser_linebreak(void);
void					parser_new_line_list(void);

#endif
