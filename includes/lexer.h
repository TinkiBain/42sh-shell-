/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggwin-go <ggwin-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/29 19:09:37 by dwisoky           #+#    #+#             */
/*   Updated: 2019/09/23 14:26:32 by ggwin-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_H
# define LEXER_H

# include "libft.h"
# include "xfuncs.h"

typedef struct			s_lex
{
	struct s_lex		*next;
	struct s_lex		*back;
	char				*lexem;
	int					type;
	int					if_alias;
}						t_lex;

int						g_if_alias;

# define NEWLINE		1
# define SEMI			2
# define DSEMI			3
# define AND_IF			4
# define OR_IF			5
# define PIPE			6
# define WORD			7
# define IO_NUMBER		8
# define JOB			9
# define ANDGREAT		10
# define ANDDGREAT		11
# define ANDLESS		12
# define CLOBBER		13
# define GREAT			14
# define DGREAT			15
# define GREATAND		16
# define LESS			17
# define DLESS			18
# define TLESS			19
# define DLESSDASH		20
# define LESSAND		21
# define LESSGREAT		22
# define DLESSAND		23
# define LBRACKET		24
# define RBRACKET		25
# define NOT_VALID_ID	26

t_lex					*lexer(char *str);
void					lexer_free_all(t_lex *lex);
void					init_lex(int type, void *lexem, t_lex **lex);
char					*lexer_check_token(char *str, t_lex **lex);
int						lexer_check_spec_symbol(char c);
void					print_lexem(t_lex *lex);
char					*lexer_check_io_number(char *str, t_lex **lex);
char					*lexer_find_char(char *str, char c);
char					*lexer_find_word(char *str, t_lex **lex);
char					*lexer_find_dollar(char *str);
char					*lexer_find_rbrace(char *str);
char					*lexer_check_bracket(char *str, t_lex **lex);

#endif
