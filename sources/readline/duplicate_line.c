/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   duplicate_line.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelisan <gmelisan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/15 07:04:37 by gmelisan          #+#    #+#             */
/*   Updated: 2019/08/17 16:27:49 by gmelisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_readline.h"

t_line	*duplicate_line(t_line *line)
{
	t_line	*new;

	new = ft_xmemalloc(sizeof(t_line));
	ft_memcpy(new, line, sizeof(t_line));
	new->str = ft_xmemalloc(sizeof(t_string));
	*new->str = str_xduplicate(*line->str);
	new->arg = 1;
	return (new);
}

void	free_line(t_line *line)
{
	str_delete(line->str);
	str_delete(&line->keybuf);
	free(line->str);
	free(line);
}
