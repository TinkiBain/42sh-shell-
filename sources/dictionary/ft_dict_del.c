/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dict_del.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggwin-go <ggwin-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 22:13:35 by ggwin-go          #+#    #+#             */
/*   Updated: 2019/10/15 17:23:37 by ggwin-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

void	ft_dict_del(t_dict **dict)
{
	if (!dict || !*dict)
		return ;
	if (*dict != NULL)
		ft_dict_del(&((*dict)->next));
	ft_dict_del_one(dict);
}
