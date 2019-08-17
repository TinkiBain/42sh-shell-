/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_readonly_var.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggwin-go <ggwin-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/15 22:02:09 by ggwin-go          #+#    #+#             */
/*   Updated: 2019/08/15 22:52:04 by ggwin-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "variables.h"

int		check_readonly_var(const char *name)
{
	if (ft_strequ(name, "?") || ft_strequ(name, "_") ||
			ft_strequ(name, "SHELLOPTS") || ft_strequ(name, "NOCLOBBER") ||
			ft_strequ(name, "SHELL_HOME") || ft_strequ(name, "SHELL_ALIASES"))
	{
		print_var_readonly(name);
		return (1);
	}
	return (0);
}
