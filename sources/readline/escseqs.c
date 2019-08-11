/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   escseqs.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelisan </var/spool/mail/vladimir>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 23:45:47 by gmelisan          #+#    #+#             */
/*   Updated: 2019/08/11 04:27:23 by gmelisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "escseqs.h"

static int		max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

/*
** Rule: "\E[n1;n2...]a", 
** n1, n2 - numbers
** [] - optional
** ... - can be repeated any times
** a - any char
** ------------
** ex.: "\E[m", "\E[0m", "\E[0;0m", "\E[4m", "\E[40;1m"
*/

static t_string	get_escseq(t_string str, int *i)
{
	t_string	es;
	int			j;
	int			len;

	j = *i + 1;
	es = str_copy("\033");
	if (str_get(str, j) != '[' && (*i = j))
		return (es);
	str_xaddback(&es, str.s + j, 1);
	while (42)
	{
		len = 0;
		while (ft_isdigit(str_get(str, ++j)))
			len++;
		if (str_get(str, j) && len > 0)
			str_xaddback(&es, str.s + j - len, len);
		if (str_get(str, j) != ';')
			break ;
		else
			str_xaddback(&es, str.s + j, 1);
	}
	if (str_get(str, j))
		str_xaddback(&es, str.s + j, 1);
	*i = ++j;
	return (es);
}

void	pull_escseqs(t_vector *vec, t_string *str)
{
	t_string	new;
	t_escseq	tmp;
	int			i;
	int			sub;
	char		c;

	*vec = vec_xcreate(0, sizeof(t_escseq));
	new = str_create(0);
	i = 0;
	sub = 0;
	while ((c = str_get(*str, i)))
	{
		if (c == ESC)
		{
			tmp.str = get_escseq(*str, &i);
			sub += tmp.str.len;
			tmp.pos = i - sub;
			vec_xaddback(vec, &tmp);
		}
		else
		{
			str_xaddback(&new, &c, 1);
			i++;
		}
		
	}
	free(str->s);
	*str = new;
}

t_escseq	*find_escseq(t_vector es, int n)
{
	int i;

	i = 0;
	while (i < (int)es.len)
	{
		if (((t_escseq *)vec_get(es, i))->pos == n)
			return (vec_get(es, i));
		i++;
	}
	return (NULL);
}

int			count_escseq(t_vector es, int from, int until)
{
	int			i;
	int			len;
	t_escseq	*tmp;

	len = 0;
	i = -1;
	while (++i < (int)es.len)
	{
		tmp = (t_escseq *)vec_get(es, i); 
		if (tmp->pos >= from && tmp->pos <= until)
			len += tmp->str.len;
	}
	return (len);
}

void		shift_escseq(t_vector *es, int from, int count)
{
	int			i;
	t_escseq	*tmp;

	i = -1;
	while (++i < (int)es->len)
	{
		tmp = (t_escseq *)vec_get(*es, i);
		if (tmp->pos >= from)
			tmp->pos += count;
	}
}

static int	in_range(t_escseq *es, int start, int end)
{
	if (es && es->pos >= start && es->pos <= end)
		return (1);
	return (0);
}

int			test_escseq_unmatch(t_vector v_old, t_vector v_new,
								int start, int end)
{
	int			i;
	t_escseq	*es_old;
	t_escseq	*es_new;

	i = -1;
	while (++i < max(v_new.len, v_old.len))
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
