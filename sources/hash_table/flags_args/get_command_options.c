/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_command_options.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggwin-go <ggwin-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/29 17:08:40 by wtalea            #+#    #+#             */
/*   Updated: 2019/09/05 23:06:48 by gmelisan         ###   ########.fr       */
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
