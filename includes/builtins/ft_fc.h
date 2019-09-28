/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fc.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggwin-go <ggwin-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 14:12:39 by gmelisan          #+#    #+#             */
/*   Updated: 2019/09/28 18:53:09 by gmelisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FC_H
# define FT_FC_H

# include "builtins.h"

typedef struct	s_cmd_opt
{
	t_uint		e : 1;
	t_uint		l : 1;
	t_uint		n : 1;
	t_uint		r : 1;
	t_uint		s : 1;
}				t_cmd_opt;

t_dlist		*ft_fc_find_arg(const char *str);
t_dlist		*ft_fc_find_arg_number(const char *str);

int			ft_fc_list(const char **argv, t_cmd_opt opt);
int			ft_fc_reexec(const char **argv);

#endif
