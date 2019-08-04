/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_get.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelisan <gmelisan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/10 18:11:49 by gmelisan          #+#    #+#             */
/*   Updated: 2019/03/10 18:52:55 by gmelisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vector.h"

void	*vec_get(t_vector vec, int i)
{
	if (i < 0)
		return (0);
	if ((size_t)i < vec.len)
		return ((void *)((t_uchar *)vec.v + (i * vec.size)));
	return (0);
}
