/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_dict.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggwin-go <ggwin-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 13:56:20 by ggwin-go          #+#    #+#             */
/*   Updated: 2019/10/12 17:36:36 by ggwin-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

t_dict	*ft_init_dict(const char *key, const char *value)
{
	t_dict	*dict;

	if (!key)
		return (NULL);
	dict = (t_dict *)ft_xmemalloc(sizeof(t_dict));
	dict->key = ft_xstrdup(key);
	dict->key_len = ft_strlen(key);
	dict->value = ft_xstrdup(value);
	dict->value_len = ft_strlen(value);
	dict->next = NULL;
	return (dict);
}
