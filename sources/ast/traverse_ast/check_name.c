/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_name.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggwin-go <ggwin-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 21:17:02 by dwisoky           #+#    #+#             */
/*   Updated: 2019/10/13 17:17:44 by wtalea           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

/*
** Grammar rule rule 5 and 8
*/

static int	print_error_name(char *str)
{
	str = ft_xstrjoin("`", str);
	str = ft_xstrrejoin(str, "'", 1);
	print_error(str, "not a valid identifier");
	ft_strdel(&str);
	return (1);
}

int			check_name(char *str)
{
	if (*str >= '0' && *str <= '9')
		return (print_error_name(str));
	while (*str)
	{
		if ((*str >= '0' && *str <= '9') || (*str == '_') || (*str >= 'a' &&
					*str <= 'z') || (*str >= 'A' && *str <= 'Z'))
			++str;
		else
			return (print_error_name(str));
	}
	return (0);
}
