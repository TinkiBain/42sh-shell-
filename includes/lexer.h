/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggwin-go <ggwin-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/26 17:21:39 by dwisoky           #+#    #+#             */
/*   Updated: 2019/08/07 22:04:30 by dwisoky          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_H
# define LEXER_H

# include "libft.h"

# define PIPE_SYMB	1
# define SEMICOLON	2
# define WORD		4
# define AND_IF		8
# define OR_IF		16
# define BANG		32
# define LESS		64
# define DLESS		128
# define DLESSDASH	256
# define TLESS		512
# define LESSAND	1024
# define LESSGREAT	2048
# define GREAT		4096
# define DGREAT		8192
# define GREATAND	16384
# define ANDGREAT	32768
# define ANDDGREAT	65536
# define CLOBBER	131072

typedef struct		s_lex
{
	int				fd;
	char			*lexeme;
	int				type;
	struct s_lex	*next;
	struct s_lex	*prev;
}					t_lex;

char				*lexer_get_token(char *str, t_lex **lex);
char				*lexer_find_simbol(char *str, char c);
char				*lexer_bang(char *str, t_lex *lex);
size_t				lexer_check_word(char *str, t_lex **lex);
size_t				lexer_and_or(char *str, t_lex **lex);
size_t				lexer_check_redir(char *str, t_lex **lex);
void				lexer_free_all(t_lex *lex);
int					ft_isspec(char c);

#endif
