/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_builtin.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggwin-go <ggwin-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/03 19:32:27 by ggwin-go          #+#    #+#             */
/*   Updated: 2019/08/03 21:29:12 by ggwin-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		check_builtin(char *cmd)
{
	if (ft_strequ(cmd, "exit") || ft_strequ(cmd, "cd") ||
			ft_strequ(cmd, "echo") || ft_strequ(cmd, "env") ||
			ft_strequ(cmd, "setenv") || ft_strequ(cmd, "unsetenv") ||
			ft_strequ(cmd, "hash") || ft_strequ(cmd, "type"))
		return (1);
	return (0);
}
