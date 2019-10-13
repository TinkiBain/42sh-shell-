/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_xduplicate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelisan <gmelisan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 02:00:20 by gmelisan          #+#    #+#             */
/*   Updated: 2019/10/14 02:00:22 by gmelisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "xfuncs.h"

t_string		str_xduplicate(t_string str)
{
	t_string new;

	new = str_duplicate(str);
	if (!new.s)
		die();
	return (new);
}
