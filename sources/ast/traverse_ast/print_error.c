/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggwin-go <ggwin-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/25 18:53:05 by ggwin-go          #+#    #+#             */
/*   Updated: 2019/08/29 17:25:57 by ggwin-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

void	print_error(const char *cmd, const char *error)
{
	ft_putstr_fd(g_project_name, 2);
	ft_putstr_fd(": ", 2);
	ft_putstr_fd(cmd, 2);
	ft_putendl_fd(error, 2);
}
