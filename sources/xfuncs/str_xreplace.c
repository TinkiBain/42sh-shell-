/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_xreplace.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelisan <gmelisan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 20:31:33 by gmelisan          #+#    #+#             */
/*   Updated: 2019/10/23 21:03:06 by gmelisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "xfuncs.h"

t_string	*str_xreplace(t_string *str, const char *what, const char *with)
{
	t_string	*p;

	if (!str || !what || !with || !ft_strlen(what) || !ft_strlen(with))
		return (str);
	if (!(p = str_replace(str, what, with)))
		die();
	return (p);
}
