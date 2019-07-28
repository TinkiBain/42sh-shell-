/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelisan <gmelisan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 16:57:04 by gmelisan          #+#    #+#             */
/*   Updated: 2019/01/29 17:36:28 by gmelisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*get_color(const char *format, int i)
{
	int		start;
	char	*str;

	start = i + 1;
	while (format[i] != '}')
	{
		if (format[i] == '\0')
			return (NULL);
		i++;
	}
	str = ft_strnew(i - start);
	ft_strncpy(str, &format[start], i - start);
	return (str);
}
