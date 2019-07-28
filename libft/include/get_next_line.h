/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelisan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 19:48:23 by gmelisan          #+#    #+#             */
/*   Updated: 2019/02/11 05:55:50 by gmelisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include "libft.h"

# define BUFF_SIZE 10

typedef struct	s_gnlbuf
{
	int			fd;
	char		buf[BUFF_SIZE];
}				t_gnlbuf;

int				get_next_line(const int fd, char **line);

#endif
