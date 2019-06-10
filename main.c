/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwisoky <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/03 20:32:09 by dwisoky           #+#    #+#             */
/*   Updated: 2019/06/08 17:17:20 by dwisoky          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

t_attr_left		*initialize_left(int spec, char *right, int left)
{
	t_attr_left	*attr;

	attr = (t_attr*)ft_xmalloc(sizeof(t_attr));
	attr->spec = spec;
	attr->right = ft_strdup(right);
	attr->left = left;
	return (attr);
}

t_attr_right	*intialize_right(int spec,

t_exec	*initialize_exec(int count, char **av)
{
	t_exec	*exec;
	int		i;

	exec = (t_exec*)ft_xmalloc(sizeof(t_exec));
	exec->av = (char**)ft_xmalloc(sizeof(char*) * (count + 1));
	i = 0;
	while (*av)
	{
		exec->av[i] = ft_strdup(*av);
		++av;
		i++;
	}
	exec->right = NULL;
	exec->left = NULL;
	exec->next = NULL;
	return (exec);
}

int		main(int ac, char **av)
{
	t_exec	*cmd;

	cmd = initialize_exec(ac - 1, av + 1);
	cmd->left = NULL;
	cmd->left = initialize_left(LLL, "test", 1, NULL);
	cmd->right = initialize_right(R, "test", 1, NULL);
	cmd->right->next = initialize_attr(RR, "test", 1, NULL);
//	cmd->right->next->next = initialize_attr(R, "test1", 1, NULL);
//	cmd->left->next = initialize_attr(LL, "F", 1, NULL);
//	cmd->left->next->next = initialize_attr(LL, "D", 1, NULL);
	exec(cmd);
	return (0);
}
