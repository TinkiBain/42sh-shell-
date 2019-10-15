/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dict_remove_elem.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggwin-go <ggwin-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 19:00:21 by ggwin-go          #+#    #+#             */
/*   Updated: 2019/10/15 17:23:44 by ggwin-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

void	ft_dict_remove_elem(t_dict **dict, t_dict *elem)
{
	t_dict	*prev;
	t_dict	*tmp;

	if (!dict || !*dict || !elem)
		return ;
	prev = NULL;
	tmp = *dict;
	while (tmp)
	{
		if (tmp == elem)
		{
			if (prev)
				prev->next = tmp->next;
			else
				*dict = tmp->next;
			ft_dict_del_one(&tmp);
			break ;
		}
		tmp = tmp->next;
		prev = tmp;
	}
}
