/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ast.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggwin-go <ggwin-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/18 21:14:47 by ggwin-go          #+#    #+#             */
/*   Updated: 2019/08/24 20:27:22 by ggwin-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINT_AST_H
# define PRINT_AST_H

# include "parser.h"
# include "lexer.h"
# include "libft.h"

void	print_ast(t_pars_list *root);

void	print_ast_cmd(t_cmd *cmd);
void	print_ast_io_redir(t_io_redirect *redir);
void	print_ast_token_assignment_word(char *word);
void	print_ast_token_number(int type);
void	print_ast_token_word(char *word);

#endif
