/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggwin-go <ggwin-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/05 21:17:32 by ggwin-go          #+#    #+#             */
/*   Updated: 2019/09/04 15:12:58 by ggwin-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AST_H
# define AST_H

# include "lexer.h"
# include "parser.h"
# include "exec.h"

void		handle_token_assignment_word(char *word, char ***env);
void		push_back_av(char ***av, char *elem);

void		traverse_ast(t_pars_list *root);
void		traverse_cmd(t_cmd *cmd, char **env, int in_fork);
void		traverse_pipeline(t_pipeline *root);
int			check_cmd(const char *cmd);

void		print_ast(t_pars_list *root);

void		dollar(int *j, char **str);
char		*tilda_check(char *str);
char		*tdq(char *str);

int			check_spec_symbol(char c);
int			check_spec_symboli_dq(char c);

#endif
