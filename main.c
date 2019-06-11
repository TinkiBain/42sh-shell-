/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggwin-go <ggwin-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/03 20:32:09 by dwisoky           #+#    #+#             */
/*   Updated: 2019/06/11 12:38:16 by dwisoky          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

int		main(int ac, char **av)
{
	t_exec	*cmd;

	cmd = init_exec(ac - 1, av + 1, 0);
	cmd->attr = NULL;
//	cmd->attr = initialize_left(LLL, "test", 1, NULL);
	cmd->attr= init_attr(5, 1, 1, "test");
//	cmd->attr->next = init_attr(32, 1, 2, "test1");
//	cmd->right->next->next = initialize_attr(R, "test1", 1, NULL);
//	cmd->left->next = initialize_attr(LL, "F", 1, NULL);
//	cmd->left->next->next = initialize_attr(LL, "D", 1, NULL);
	exec(cmd);
	return (0);
}
