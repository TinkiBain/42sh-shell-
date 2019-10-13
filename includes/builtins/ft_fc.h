/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fc.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelisan <gmelisan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 14:12:39 by gmelisan          #+#    #+#             */
/*   Updated: 2019/10/13 14:21:40 by gmelisan         ###   ########.fr       */
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

t_vector		ft_fc_build_vector(const char **argv, int *start, t_cmd_opt opt,
				void (*get_first_last)(const char **, t_dlist **, t_dlist **));
t_dlist			*ft_fc_find_arg(const char *str);
t_dlist			*ft_fc_find_arg_number(const char *str);

int				ft_fc_list(const char **argv, t_cmd_opt opt);
int				ft_fc_reexec(const char **argv, t_pjobs *local);
int				ft_fc_edit(const char **argv, t_cmd_opt opt, t_pjobs *local);
char			**ft_fc_edit_build_argv(char *path, t_cmd_opt opt);
int				ft_fc_edit_run_editor(char **argv);
int				ft_fc_edit_execute(char *path, t_pjobs *local);

#endif
