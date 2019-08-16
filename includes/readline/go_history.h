/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   go_history.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wtalea <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/16 17:22:42 by wtalea            #+#    #+#             */
/*   Updated: 2019/08/16 17:31:41 by wtalea           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GO_HISTORY
# define GO_HISTORY

# include "ft_readline.h"

int				next_history_check(t_line *line);
int				previous_history_check(t_line *line);
int				len_history(t_line *line);

#endif
