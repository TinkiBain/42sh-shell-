/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_builtin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggwin-go <ggwin-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/25 21:37:10 by ggwin-go          #+#    #+#             */
/*   Updated: 2019/09/13 19:01:25 by dwisoky          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

int			is_builtin(const char *cmd)
{
	if (*cmd == '%' || ft_strequ(cmd, "exit") || ft_strequ(cmd, "cd") ||
			ft_strequ(cmd, "echo") || ft_strequ(cmd, "type") ||
			ft_strequ(cmd, "hash") || ft_strequ(cmd, "env") ||
			ft_strequ(cmd, "set") || ft_strequ(cmd, "unset") ||
			ft_strequ(cmd, "fc") || ft_strequ(cmd, "export") ||
			ft_strequ(cmd, "jobs") || ft_strequ(cmd, "fg") ||
			ft_strequ(cmd, "bg") || ft_strequ(cmd, "kill") ||
			ft_strequ(cmd, "alias") || ft_strequ(cmd, "unalias"))
		return (1);
	return (0);
}
