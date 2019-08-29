/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_var_readonly.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggwin-go <ggwin-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/15 22:16:12 by ggwin-go          #+#    #+#             */
/*   Updated: 2019/08/29 17:33:01 by ggwin-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "defs.h"

int		print_var_readonly(const char *var, size_t name_len)
{
	ft_putstr_fd(g_project_name, STDERR);
	ft_putstr_fd(": ", STDERR);
	write(STDERR, var, name_len);
	ft_putendl_fd(": readonly variable", STDERR);
	return (1);
}
