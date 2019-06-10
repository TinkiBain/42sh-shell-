/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_exec.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggwin-go <ggwin-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 18:28:20 by ggwin-go          #+#    #+#             */
/*   Updated: 2019/06/10 20:39:35 by ggwin-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"
#include <stdio.h>

t_exec	*init_exec(int count, char **av)
{
	t_exec	*exec;
	int		i;

	exec = (t_exec*)ft_xmalloc(sizeof(t_exec));
	exec->av = (char**)ft_xmalloc(sizeof(char*) * (count + 1));
	i = 0;
	while (*av)
	{
		printf("%s\n", *av);
		exec->av[i] = ft_strdup(*av);
		++av;
		i++;
	}
	exec->attr = NULL;
	exec->next = NULL;
	return (exec);
}
