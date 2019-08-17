/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   undo.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wtalea <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/16 13:48:35 by wtalea            #+#    #+#             */
/*   Updated: 2019/08/17 17:21:38 by wtalea           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UNDO_H
# define UNDO_H

# include "ft_readline.h"

typedef	struct		s_undo_item
{
	t_string	string;
	int			cpos;
	int			lenh;
}					t_undo_item;

void				push_undo_list(t_line *line);
t_undo_item			*pop_undo_list(t_list **undo);

#endif
