/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggwin-go <ggwin-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/05 21:17:32 by ggwin-go          #+#    #+#             */
/*   Updated: 2019/10/23 16:12:27 by ggwin-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AST_H
# define AST_H

# include "lexer.h"
# include "parser.h"
# include "builtins.h"
# include "redirect.h"
# include "jobs.h"

/*
**		Functions for make source substring from lexem:
*/

char	*get_lexem_value(int type);
char	*get_job_name(t_lex *lex, t_lex *lex_end);
char	*get_process_name(t_command *command);

/*
**		Functions for call subshell or check/launch command:
*/

int		call_exec(int ac, const char **av, t_pjobs *local);
int		call_subshell(char *str, t_pjobs *local);
int		check_cmd(const char *cmd);
int		check_name(char *str);

/*
**		Functions for traverse Abstruct Sintax Tree:
*/

void	traverse_ast(t_complete_cmd *root);
void	traverse_pipe_sequence(t_pipe_sequence *elem, int sep);
void	traverse_pipe(t_pipe_sequence *pipe_seq, int fd, t_pjobs **local,
															int *counter);
int		traverse_redirect_list(t_redirect_list *list);
void	traverse_command(t_command *cmd, int in_fork, t_pjobs *local);
void	traverse_simple_command(t_simple_cmd *cmd, int in_fork, t_pjobs *local);
void	traverse_compound_command(t_compound_cmd *cmd, t_pjobs *local);
void	traverse_compound_list(t_compound_list *list, t_pjobs *local);
void	traverse_if_clause(t_if_clause *list, t_pjobs *local);
void	traverse_for_clause(t_for_clause *list, t_pjobs *local);
void	traverse_while_clause(t_while_clause *list, t_pjobs *local);
void	traverse_until_clause(t_while_clause *list, t_pjobs *local);
void	traverse_case_clause(t_case_clause *list, t_pjobs *local);
void	traverse_function_definition(t_func_definition *func);

#endif
