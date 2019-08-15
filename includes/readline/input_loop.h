/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_loop.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelisan </var/spool/mail/vladimir>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 16:45:53 by gmelisan          #+#    #+#             */
/*   Updated: 2019/08/15 05:58:30 by gmelisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INPUT_LOOP_H
# define INPUT_LOOP_H

# include "ft_readline.h"

int		input_loop(t_line *line);
int		vi_input_loop(t_line *line);
int		vi_input_one(t_line *line);

extern int	g_logfd;

#endif
