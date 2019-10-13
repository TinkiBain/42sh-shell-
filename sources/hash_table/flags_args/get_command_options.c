/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_command_options.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wtalea <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/29 17:08:40 by wtalea            #+#    #+#             */
/*   Updated: 2019/10/13 12:21:38 by wtalea           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hash.h"

char		**get_command_options(char *name)
{
	t_hash		*table;
	int			len;

	table = NULL;
	if ((table = get_hash_struct(name)))
	{
		len = 0;
		while (table->flags_args && table->flags_args[len])
			len++;
		ft_arr_str_qsort(table->flags_args, len);
		return (table->flags_args);
	}
	return (NULL);
}
