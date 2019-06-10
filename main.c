/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggwin-go <ggwin-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/03 20:32:09 by dwisoky           #+#    #+#             */
/*   Updated: 2019/06/10 18:33:52 by ggwin-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

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
