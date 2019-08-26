/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   escseq_test_unmatch.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelisan <gmelisan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/25 23:39:07 by gmelisan          #+#    #+#             */
/*   Updated: 2019/08/26 15:11:23 by gmelisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "escseqs.h"

static int	in_range(t_escseq *es, int start, int end)
{
	if (es && es->pos >= start && es->pos <= end)
		return (1);
	return (0);
}

int			escseq_test_unmatch(t_vector v_old, t_vector v_new,
								int start, int end)
{
	int			i;
	t_escseq	*es_old;
	t_escseq	*es_new;

	i = -1;
	while (++i < max_int(v_new.len, v_old.len))
	{
		es_old = (t_escseq *)vec_get(v_old, i);
		es_new = (t_escseq *)vec_get(v_new, i);
		if (in_range(es_old, start, end) && !in_range(es_new, start, end))
			return (1);
		if (!in_range(es_old, start, end) && in_range(es_new, start, end))
			return (1);
		if (in_range(es_old, start, end) && in_range(es_new, start, end) &&
			(es_old->pos != es_new->pos ||
			!ft_strequ(es_new->str.s, es_old->str.s)))
			return (1);
	}
	return (0);
}
