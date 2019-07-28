/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_qsort.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelisan <gmelisan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 05:52:01 by gmelisan          #+#    #+#             */
/*   Updated: 2019/02/13 11:48:59 by gmelisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_QSORT_H
# define FT_QSORT_H

# include "libft.h"

struct				s_qsortarr
{
	void			*arr;
	size_t			size;
	int				(*cmp)(const void *, const void *);
};

void				ft_qsort(void *ptr, size_t count, size_t size,
								int (*cmp)(const void *, const void *));

#endif
