/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlst2end.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelisan <gmelisan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/21 19:45:06 by gmelisan          #+#    #+#             */
/*   Updated: 2019/09/21 19:46:27 by gmelisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_dlst2end(t_dlist **alst)
{
	t_dlist *p;

	if (!alst || !*alst)
		return ;
	p = *alst;
	while (p->next)
		p = p->next;
	*alst = p;
}
