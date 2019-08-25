/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   go_history.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggwin-go <ggwin-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/16 17:22:42 by wtalea            #+#    #+#             */
/*   Updated: 2019/08/25 13:55:51 by ggwin-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GO_HISTORY_H
# define GO_HISTORY_H

# include "ft_readline.h"

int				next_history_check(t_line *line);
int				previous_history_check(t_line *line);
int				len_history(t_line *line);

#endif
