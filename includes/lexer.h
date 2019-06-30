/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggwin-go <ggwin-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/26 17:21:39 by dwisoky           #+#    #+#             */
/*   Updated: 2019/06/30 21:38:31 by dwisoky          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_H
# define LEXER_H

# include "sh.h"

# define PIPE 1
# define SEMICOLON 2
# define WORD 4
# define AND 8
# define OR 16
# define GREAT 32
# define DGREAT 64
# define GREATAND 128
# define LESS 256
# define DLESS 512
# define TLESS 1024
# define DLESSDASH 2048
# define LESSAND 4096
# define LESSGREAT 8192
# define ANDGREAT 16384
# define ANDDGREAT 32768

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
size_t				lexer_check_word(char *str, t_lex **lex);
size_t				lexer_and_or(char *str, t_lex **lex);
size_t				lexer_check_redir(char *str, t_lex **lex);
int					ft_isspec(char c);

#endif
