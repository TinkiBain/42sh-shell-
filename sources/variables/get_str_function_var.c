/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_str_function_var.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggwin-go <ggwin-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 20:58:01 by ggwin-go          #+#    #+#             */
/*   Updated: 2019/10/15 17:22:40 by ggwin-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

char		*get_str_function_var(const char *name, const char *value)
{
	char	*str;

	str = ft_xstrjoin("BASH_FUNC_", name);
	str = ft_xstrrejoin(str, "%%=() { ", 1);
	if (value)
	{
		str = ft_xstrrejoin(str, value, 1);
		str = ft_xstrrejoin(str, "\n}", 1);
	}
	return (str);
}
