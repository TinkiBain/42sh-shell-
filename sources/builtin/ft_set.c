/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggwin-go <ggwin-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/16 17:38:16 by ggwin-go          #+#    #+#             */
/*   Updated: 2019/08/18 17:36:30 by ggwin-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

static int	handle_set_arg(const char **av)
{
	if (ft_strequ(*av, "-p"))
		print_var_names();
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
			print_all_vars();
		else
			return (handle_set_arg(av));
	}
	return (0);
}
