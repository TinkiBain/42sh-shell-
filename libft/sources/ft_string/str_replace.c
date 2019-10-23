/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_replace.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelisan <gmelisan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 19:49:25 by gmelisan          #+#    #+#             */
/*   Updated: 2019/10/23 22:37:33 by gmelisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

t_string	*str_replace(t_string *str, const char *what, const char *with)
{
	size_t	i;
	int		len_what;
	int		len_with;

	len_what = ft_strlen(what);
	len_with = ft_strlen(with);
	if (!str || !what || !with || !len_what || !len_with)
		return (str);
	i = -1;
	while (++i < str->len)
		if (ft_strncmp(str->s + i, what, len_what) == 0)
			break ;
	if (i == str->len)
		return (str);
	str_remove(str, i, ft_strlen(what));
	if (!str_insert(str, i, with, len_with))
		return (NULL);
	return (str);
}
