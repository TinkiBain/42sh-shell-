/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggwin-go <ggwin-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/05 21:17:32 by ggwin-go          #+#    #+#             */
/*   Updated: 2019/08/12 18:17:17 by jterry           ###   ########.fr       */
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

void		print_ast(t_pars_list *root);

char		*tilda_check(char *str);
char		*ft_dollar(char *str);
char		*qoutes(char *str);

#endif
