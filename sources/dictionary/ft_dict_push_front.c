/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dict_push_front.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggwin-go <ggwin-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/02 14:14:34 by ggwin-go          #+#    #+#             */
/*   Updated: 2019/10/12 17:29:55 by ggwin-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

void	ft_dict_push_front(t_dict **dict, t_dict *new_elem)
{
	if (!dict || !new_elem)
		return ;
	new_elem->next = *dict;
	*dict = new_elem;
}
