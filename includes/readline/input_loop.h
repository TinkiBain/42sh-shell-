/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_loop.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelisan </var/spool/mail/vladimir>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 16:45:53 by gmelisan          #+#    #+#             */
/*   Updated: 2019/08/04 11:58:22 by gmelisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INPUT_LOOP_H
# define INPUT_LOOP_H

# include "ft_readline.h"

int		input_loop(t_line *line, t_vector *key_bindings);
int		vi_input_loop(t_line *line, t_vector *key_bindings);

extern int	g_logfd;

#endif
