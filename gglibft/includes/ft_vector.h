/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggwin-go <ggwin-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/19 22:07:04 by ggwin-go          #+#    #+#             */
/*   Updated: 2019/07/04 19:39:16 by ggwin-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_VECTOR_H
# define FT_VECTOR_H

# include "libft.h"
# define SIZE_DELTA 10

typedef struct	s_vector
{
	void		**data;
	size_t		capacity;
	size_t		count;
}				t_vector;

int				ft_vector_add(t_vector *vector, void *elem);
int				ft_vector_remove(t_vector *vector, void *elem);
t_vector		*ft_vector_init(void *elem);

#endif
