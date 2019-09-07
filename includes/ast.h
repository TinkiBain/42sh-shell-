/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggwin-go <ggwin-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/05 21:17:32 by ggwin-go          #+#    #+#             */
/*   Updated: 2019/09/07 16:53:42 by ggwin-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AST_H
# define AST_H

# include "lexer.h"
# include "parser.h"
# include "exec.h"

int			check_cmd(const char *cmd);
void		handle_token_assignment_word(char *word, char ***env);
void		traverse_pipe_sequence(t_pipe_sequence *elem, char **env);
void		traverse_ast(t_complete_cmd *root);
void		traverse_cmd(t_simple_cmd *cmd, char **env, int in_fork);

void		push_back_av(char ***av, char *elem);

// void		print_ast(t_pars_list *root);

void		dollar(int *j, char **str);
char		*tilda_check(char *str);
char		*tdq(char *str);

int			check_spec_symbol(char c);
int			check_spec_symboli_dq(char c);

#endif
