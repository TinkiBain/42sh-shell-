/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_loop.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggwin-go <ggwin-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 16:45:53 by gmelisan          #+#    #+#             */
/*   Updated: 2019/08/25 13:56:01 by ggwin-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INPUT_LOOP_H
# define INPUT_LOOP_H

# include "ft_readline.h"

# define KEYBUF_SIZE			32

int		input_loop(t_line *line);
int		em_input_loop(t_line *line);
int		vi_input_loop(t_line *line);
int		vi_input_one(t_line *line);
int		is_ansiseq(char buf[KEYBUF_SIZE]);

#endif
