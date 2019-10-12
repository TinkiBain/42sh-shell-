/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dict_del_one.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggwin-go <ggwin-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 22:02:59 by gmelisan          #+#    #+#             */
/*   Updated: 2019/10/12 19:53:56 by ggwin-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

void	ft_dict_del_one(t_dict **dict)
{
	if (!dict || !*dict)
		return ;
	ft_strdel(&(*dict)->key);
	ft_strdel(&(*dict)->value);
	free(*dict);
	*dict = NULL;
}
