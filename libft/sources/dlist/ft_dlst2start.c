/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlst2start.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelisan <gmelisan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/21 19:43:24 by gmelisan          #+#    #+#             */
/*   Updated: 2019/09/21 19:46:38 by gmelisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_dlst2start(t_dlist **alst)
{
	t_dlist *p;

	if (!alst || !*alst)
		return ;
	p = *alst;
	while (p->prev)
		p = p->prev;
	*alst = p;
}
