/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwisoky <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/04 17:44:12 by dwisoky           #+#    #+#             */
/*   Updated: 2019/06/10 16:46:06 by dwisoky          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef SH_H
# define SH_H

# define R 1
# define RR 2
# define DR 4
# define RD 8
# define C 16
# define L 32
# define LL 64
# define LLL 128
# deifne O 256

typedef struct				s_bits
{
	int		R:1;
	int		RR:1;
	int		DR:1;
	int		RD:1;
	int		C:1;
	int		L:1;
	int		LL:1;
	int		LLL:1;
	int		O:1;
	int		R:1;
}							t_bits;

union						u_spec
{
	unsigned int			value;
	t_bits					bits;
}

/*
typedef struct				s_attr_left
{
	struct s_attr			*next;
	char					*file;
	int						left_fd;
	int						spec;
}							t_attr_left;

typedef struct				s_attr_right
{
	struct s_attr_right		*next;
	char					*file;
	int						spec;
	int						left_fd;
	int						right_fd;
	int						close;
}							t_attr_right;
*/

typedef struct				s_attr
{
	struct s_attr			*next;
	char					*file;
	int						spec;
	
}							t_attr;

typedef struct				s_exec
{
	struct s_exec			*next;
	t_attr_left				*left;
	t_attr_right			*right;
	char					**av;
}							t_exec;

void	exec(t_exec *cmd);

# endif
