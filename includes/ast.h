/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggwin-go <ggwin-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/05 21:17:32 by ggwin-go          #+#    #+#             */
/*   Updated: 2019/08/06 18:07:37 by ggwin-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AST_H
# define AST_H

# include "lexer.h"
# include "parser.h"
# include "exec.h"

void		call_exec(char **av, char ***env);
int			check_builtin(char *cmd);
void		handle_token_assignment_word(char *word);
void		push_back_av(char ***av, char *elem);

void		traverse_ast(t_pars_list *root);
void		traverse_cmd(t_cmd *cmd);
void		redirect(t_io_redirect *redir);
void		traverse_pipeline(t_pipeline *root);

void		print_ast(t_pars_list *root);

#endif
