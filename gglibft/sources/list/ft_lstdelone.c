/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggwin-go <ggwin-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/02 13:46:34 by ggwin-go          #+#    #+#             */
/*   Updated: 2019/04/23 23:06:40 by ggwin-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list **alst)
{
	if (!alst || !*alst)
		return ;
	free((*alst)->name);
	free((*alst)->path);
	free(*alst);
	*alst = NULL;
}
