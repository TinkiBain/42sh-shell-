/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_dict.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggwin-go <ggwin-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 14:25:26 by ggwin-go          #+#    #+#             */
/*   Updated: 2019/10/12 17:30:45 by ggwin-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

t_dict	*ft_get_dict(t_dict *dict, const char *key)
{
	if (key)
		while (dict)
		{
			if (ft_strequ(key, dict->key))
				return (dict);
			dict = dict->next;
		}
	return (NULL);
}
