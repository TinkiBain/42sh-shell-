/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_builtin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggwin-go <ggwin-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/25 21:37:10 by ggwin-go          #+#    #+#             */
/*   Updated: 2019/08/25 23:07:08 by ggwin-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

int			is_builtin(const char *cmd)
{
	if (ft_strequ(cmd, "exit") || ft_strequ(cmd, "cd") ||
			ft_strequ(cmd, "echo") || ft_strequ(cmd, "type") ||
			ft_strequ(cmd, "setenv") || ft_strequ(cmd, "unsetenv") ||
			ft_strequ(cmd, "hash") || ft_strequ(cmd, "env") ||
			ft_strequ(cmd, "set") || ft_strequ(cmd, "unset") ||
			ft_strequ(cmd, "fc"))
		return (1);
	return (0);
}
