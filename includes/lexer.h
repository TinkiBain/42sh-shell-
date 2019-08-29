/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwisoky <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/29 19:09:37 by dwisoky           #+#    #+#             */
/*   Updated: 2019/08/29 20:48:05 by dwisoky          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_H
# define LEXER_H

# include "libft.h"

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

t_lex		*lexer(char *str);
void		init_lex(int type, void *lexem, t_lex **lex);
char		*lexer_check_reserved_word(char *str, t_lex **lex);
char		*lexer_check_token(char *str, t_lex **lex);
int			lexer_check_spec_symbol(char c);
void		print_lexem(t_lex *lex);

#endif
