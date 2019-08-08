/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggwin-go <ggwin-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/04 17:44:12 by dwisoky           #+#    #+#             */
/*   Updated: 2019/08/08 22:03:12 by ggwin-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SH_H
# define SH_H

# include <sys/wait.h>
# include "defs.h"
# include "libft.h"
# include "ast.h"
# include "hash.h"
# include "ft_readline.h"
# include "environment.h"
# include "lib_wtalea.h"

typedef struct	s_bits
{
	unsigned char	r : 1;
	unsigned char	rr : 1;
	unsigned char	rd : 1;
	unsigned char	l : 1;
	unsigned char	ll : 1;
	unsigned char	lll : 1;
	unsigned char	ld : 1;
	unsigned char	o : 1;
	unsigned char	c : 1;
}				t_bits;

typedef union	u_spec
{
	unsigned int	value;
	t_bits			bits;
}				t_spec;

typedef struct	s_attr
{
	struct s_attr	*next;
	char			*file;
	t_spec			spec;
	int				left_fd;
	int				right_fd;
}				t_attr;

typedef struct	s_exec
{
	struct s_exec	*next;
	t_attr			*attr;
	char			**av;
	int				ispipe;
}				t_exec;

t_lex				*lexer(char *str);

void				exec(t_exec *cmd);
t_exec				*init_exec(int count, char **av, int ispipe);
t_attr				*init_attr(int spec, int right_fd, int left_fd, char *file);

#endif
