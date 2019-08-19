/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_readonly_var.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggwin-go <ggwin-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/18 16:25:03 by ggwin-go          #+#    #+#             */
/*   Updated: 2019/08/19 23:54:28 by ggwin-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "variables.h"

int		check_readonly_var(const char *var, size_t name_len)
{
	if (ft_strnequ(var, "?", name_len) || ft_strnequ(var, "_", name_len) ||
			ft_strnequ(var, "SHELLOPTS", name_len) ||
			ft_strnequ(var, "NOCLOBBER", name_len) ||
			ft_strnequ(var, "SHELL_HOME", name_len) ||
			ft_strnequ(var, "SHELL_ALIASES", name_len))
	{
		print_var_readonly(var, name_len);
		return (1);
	}
	return (0);
}
