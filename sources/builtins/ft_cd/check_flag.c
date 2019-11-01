/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_flag.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwisoky <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/01 18:31:31 by dwisoky           #+#    #+#             */
/*   Updated: 2019/11/01 18:34:27 by dwisoky          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

void		*cd_error_invalid_flag(char c)
{
	print_error_vaarg("cd: -%c: invalid option\n", c);
	ft_putstr_fd("cd: usage: cd [-L|-P] [dir]\n", STDERR);
	return (NULL);
}

const char	*cd_check_flag(const char **av, int *flag)
{
	while (*av)
	{
		if (**av == '-' && *(*av + 1))
		{
			++(*av);
			while (**av)
			{
				if (**av == 'L')
					*flag = 0;
				else if (**av == 'P')
					*flag = 1;
				else
				{
					*flag = -1;
					return (cd_error_invalid_flag(**av));
				}
				++(*av);
			}
		}
		else
			return (*av);
		++av;
	}
	return (NULL);
}
