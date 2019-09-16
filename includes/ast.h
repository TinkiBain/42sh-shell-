/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggwin-go <ggwin-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/05 21:17:32 by ggwin-go          #+#    #+#             */
/*   Updated: 2019/09/16 20:00:16 by ggwin-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AST_H
# define AST_H

# include "lexer.h"
# include "parser.h"
# include "exec.h"
# include "redirect.h"

char	*get_lexem_value(int type);
char	*get_job_name(t_lex *lex, t_lex *lex_end, int separator);
char	*get_subjob_name(t_command *command);

void	traverse_pipe(t_pipe_sequence *pipe_seq, int fd, char **env,
												int in_fork, t_pjobs *local);
void	call_subshell(char *str, int sep, char **env, t_pjobs *local);
int		check_cmd(const char *cmd);
void	traverse_ast(t_complete_cmd *root);
void	traverse_pipe_sequence(t_pipe_sequence *elem, char **env, t_pjobs *local);
void	traverse_command(t_command *cmd, char **env, int in_fork, t_pjobs *local);
void	traverse_simple_command(t_simple_cmd *cmd, char **env, int in_fork);
int		traverse_redirections(t_command *cmd);
int		traverse_redirect_list(t_redirect_list *list);
void	traverse_compound_command(t_compound_cmd *cmd, char **env, int in_fork, t_pjobs *local);
void	traverse_compound_list(t_compound_list *list, char **env, t_pjobs *local);
void	traverse_function_definition(t_func_definition *func, char **env,
																int in_fork);
void	traverse_if_clause(t_if_clause *list, char **env, t_pjobs *local);
void	push_back_av(char ***av, char *elem);

void	dollar(int *j, char **str);
char	*tilda_check(char *str);
char	*tdq(char *str);

int		check_spec_symbol(char c);
int		check_spec_symboli_dq(char c);

#endif
