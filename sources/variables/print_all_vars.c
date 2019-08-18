/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_all_vars.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggwin-go <ggwin-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/18 17:28:52 by ggwin-go          #+#    #+#             */
/*   Updated: 2019/08/18 17:38:32 by ggwin-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

static int	is_duplicate(char *name, size_t name_len, char **vars)
{
	while (*vars)
	{
		if (ft_strnequ(name, *(vars++), name_len))
			return (1);
	}
	return (0);
}

static void	print_one_var(char *name, char *value)
{
	ft_putstr_len(name, value - name - 1);
	ft_putstr("='");
	ft_putstr(value);
	ft_putendl("'");
}

void		print_all_vars(void)
{
	extern char		**environ;
	extern char		**g_var;
	char			**tmp;
	char			*p;

	tmp = g_var;
	while (*tmp)
	{
		if ((p = ft_strchr(*tmp, '=')))
			print_one_var(*tmp, p + 1);
		++tmp;
	}
	tmp = environ;
	while (*tmp)
	{
		if ((p = ft_strchr(*tmp, '=')) && !is_duplicate(*tmp, p - *tmp, g_var))
			print_one_var(*tmp, p + 1);
		++tmp;
	}
}
