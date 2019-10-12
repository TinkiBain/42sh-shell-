/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_dict_value.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggwin-go <ggwin-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 13:56:20 by ggwin-go          #+#    #+#             */
/*   Updated: 2019/10/12 17:30:42 by ggwin-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

char	*ft_get_dict_value(t_dict *dict, const char *key)
{
	if (key)
		while (dict)
		{
			if (ft_strequ(key, dict->key))
				return (dict->value);
			dict = dict->next;
		}
	return (NULL);
}
