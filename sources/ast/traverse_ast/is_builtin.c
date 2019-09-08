/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_builtin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jterry <jterry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/25 21:37:10 by ggwin-go          #+#    #+#             */
/*   Updated: 2019/09/08 16:43:06 by jterry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

int			is_builtin(const char *cmd)
{
	if (ft_strequ(cmd, "exit") || ft_strequ(cmd, "cd") ||
			ft_strequ(cmd, "echo") || ft_strequ(cmd, "type") ||
			ft_strequ(cmd, "hash") || ft_strequ(cmd, "env") ||
			ft_strequ(cmd, "set") || ft_strequ(cmd, "unset") ||
			ft_strequ(cmd, "fc") || ft_strequ(cmd, "export") ||
			ft_strequ(cmd, "jobs") || ft_strequ(cmd, "fg") ||
			ft_strequ(cmd, "bg") || ft_strequ(cmd, "kill"))
		return (1);
	return (0);
}
