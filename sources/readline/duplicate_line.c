/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   duplicate_line.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelisan </var/spool/mail/vladimir>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/15 07:04:37 by gmelisan          #+#    #+#             */
/*   Updated: 2019/08/15 07:15:46 by gmelisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_readline.h"

t_line	*duplicate_line(t_line *line)
{
	t_line	*new;

	new = xmalloc(sizeof(t_line));
	ft_memcpy(new, line, sizeof(t_line));
	new->str = xmalloc(sizeof(t_string));
	*new->str = str_xduplicate(*line->str);
	return (new);
}

void	free_line(t_line *line)
{
	str_delete(line->str);
	free(line->str);
	free(line);
}
