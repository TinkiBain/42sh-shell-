/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggwin-go <ggwin-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/29 19:09:37 by dwisoky           #+#    #+#             */
/*   Updated: 2019/09/06 18:45:18 by ggwin-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_H
# define LEXER_H

# include "libft.h"
# include "xfuncs.h"

typedef struct		s_lex
{
	struct s_lex	*next;
	struct s_lex	*back;
	char			*lexem;
	int				type;
}					t_lex;

# define NEWLINE 1
# define SEMI 2
# define DSEMI 3
# define AND_IF 4
# define OR_IF 5
# define PIPE 6
# define WORD 7
# define IO_NUMBER 8
# define JOB 9
# define ANDGREAT 10
# define ANDDGREAT 11
# define ANDLESS 12
# define CLOBBER 13
# define GREAT 14
# define DGREAT 15
# define GREATAND 16
# define LESS 17
# define DLESS 18
# define TLESS 19
# define DLESSDASH 20
# define LESSAND 21
# define LESSGREAT 22
# define BANG 23
# define FOR 24
# define CASE 25
# define ESAC 26
# define WHILE 27
# define UNTIL 28
# define IF 29
# define THEN 30
# define ELSE 31
# define ELIF 32
# define FI 33
# define DO 34
# define DONE 35
# define LBRACE 36
# define RBRACE 37
# define IN 38
# define LBRACKET 39
# define RBRACKET 40

t_lex		*lexer(char *str);
void		lexer_free_all(t_lex *lex);
void		init_lex(int type, void *lexem, t_lex **lex);
int			lexer_check_reserved_word(char *str, t_lex **lex);
char		*lexer_check_token(char *str, t_lex **lex);
int			lexer_check_spec_symbol(char c);
void		print_lexem(t_lex *lex);
char		*lexer_check_io_number(char *str, t_lex **lex);
char		*lexer_find_char(char *str, char c);
char		*lexer_find_word(char *str, t_lex **lex);
char		*lexer_find_bracket(char *str);
char		*lexer_find_rbrace(char *str);

#endif
