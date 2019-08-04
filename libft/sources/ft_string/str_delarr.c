/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_delarr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelisan <gmelisan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 17:10:04 by gmelisan          #+#    #+#             */
/*   Updated: 2019/03/05 17:12:39 by gmelisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

void	str_delarr(t_string **strarr)
{
	int i;

	i = 0;
	while ((*strarr)[i].s)
		str_delete(&(*strarr)[i++]);
	free(*strarr);
	*strarr = NULL;
}
