/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_loop.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelisan <gmelisan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 16:45:53 by gmelisan          #+#    #+#             */
/*   Updated: 2019/11/02 01:23:16 by gmelisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INPUT_LOOP_H
# define INPUT_LOOP_H

# include "ft_readline.h"

# define KEYBUF_SIZE			32
# define CMD_MAXARG				999999

int		input_loop(t_line *line);
int		em_input_loop(t_line *line, char keybuf[KEYBUF_SIZE]);
int		vi_input_loop(t_line *line, char keybuf[KEYBUF_SIZE]);
int		vi_input_one(t_line *line);
int		is_ansiseq(char buf[KEYBUF_SIZE]);

#endif
