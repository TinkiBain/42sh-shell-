/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggwin-go <ggwin-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/16 17:38:16 by ggwin-go          #+#    #+#             */
/*   Updated: 2019/08/17 16:34:57 by ggwin-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

static void	print_g_var(char **g_var)
{
	char			**tmp;
	char			*p;
	char			*name;

	tmp = g_var;
	while (*tmp)
	{
		if ((p = ft_strchr(*tmp, '=')))
		{
			name = ft_strndup(*tmp, p - *tmp);
			ft_putstr(name);
			ft_putstr("='");
			ft_putstr(p + 1);
			ft_putendl("'");
		}
		++tmp;
	}
}

static int	handle_set_arg(const char **av)
{
	(void)av;
	return (0);
}

int			ft_set(const char **av)
{
	extern	char	**g_var;
	extern	char	**environ;

	if (!g_var)
		return (1);
	if (av)
	{
		if (!*av)
		{
			print_g_var(g_var);
			ft_env(av, environ);
		}
		else
			return (handle_set_arg(av));
	}
	return (0);
}
