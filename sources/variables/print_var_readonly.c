/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_var_readonly.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggwin-go <ggwin-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/15 22:16:12 by ggwin-go          #+#    #+#             */
/*   Updated: 2019/08/20 16:56:06 by ggwin-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "defs.h"

int		print_var_readonly(const char *var, size_t name_len)
{
	ft_putstr_fd(PROJECT_NAME ": ", 2);
	write(2, var, name_len);
	ft_putendl_fd(": readonly variable", 2);
	return (1);
}
