/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dict_push_back.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggwin-go <ggwin-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/02 14:14:34 by ggwin-go          #+#    #+#             */
/*   Updated: 2019/10/12 18:10:38 by ggwin-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

void	ft_dict_push_back(t_dict **dict, t_dict *new_elem)
{
	t_dict	*tmp;

	if (!dict || !new_elem)
		return ;
	if (!*dict)
		*dict = new_elem;
	else
	{
		tmp = *dict;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new_elem;
	}
}
