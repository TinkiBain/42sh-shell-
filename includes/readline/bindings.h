/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bindings.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelisan </var/spool/mail/vladimir>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/06 19:34:02 by gmelisan          #+#    #+#             */
/*   Updated: 2019/08/17 14:44:46 by gmelisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BINDINGS_H
# define BINDINGS_H

# include "ft_readline.h"
# include "line.h"

typedef void (*t_action)(t_line *line);

typedef struct	s_binding
{
	enum e_key	key;
	t_string	sequence;
	t_action	action;
}				t_binding;

void		bind(t_vector *key_bindings, int key,  t_action action);
t_binding	*find_binding(t_vector *key_bindings, t_string buf);
void		init_bindings(int vi_mode, t_vector *key_bindings);
void		update_bindings(int vi_mode, t_vector *key_bindings);
void		clear_bindings(t_vector *key_bindings);

void		bind_keys(t_vector *key_bindings);
void		vi_bind_keys(int vi_mode, t_vector *key_bindings);

int			is_vi_motion(t_action action);

#endif
