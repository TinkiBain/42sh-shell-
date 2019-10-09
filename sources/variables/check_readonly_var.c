/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_readonly_var.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggwin-go <ggwin-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/18 16:25:03 by ggwin-go          #+#    #+#             */
/*   Updated: 2019/10/09 14:28:54 by gmelisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

int		check_readonly_var(const char *var, size_t name_len)
{
	if (ft_strnequ(var, "_", name_len) ||
		ft_strnequ(var, "SHELLOPTS", name_len) ||
		ft_strnequ(var, "NOCLOBBER", name_len) ||
		ft_strnequ(var, "SHELL_HOME", name_len) ||
		ft_strnequ(var, "SHELL_ALIASES", name_len))
	{
		((char *)var)[name_len] = '\0';
		print_error(var, "readonly variable");
		return (1);
	}
	return (0);
}
