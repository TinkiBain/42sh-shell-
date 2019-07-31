/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_redir_right.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggwin-go <ggwin-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/05 20:24:55 by dwisoky           #+#    #+#             */
/*   Updated: 2019/07/31 19:10:53 by ggwin-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

static int	get_right_fd(char *file_name, int type)
{
	int		fd;
	int		flag;
	char	*tmp;

	tmp = file_name;
	while (*tmp)
	{
		if (!ft_isdigit(*(tmp++)))
			break ;
	}
	if (!*tmp)
		fd = ft_atoi(file_name);
	else
	{

	}
	return (fd);
}

int		handle_redir_right(t_io_redirect *redir)
{
	int	fd;
	int	right_fd;

	if (redir->file_name && (fd = 1))
	{
		if (redir->type & GREAT)
		{
			if ((fd = open(redir->file_name, O_WRONLY | O_CREAT | O_TRUNC)) < 0)
				return (exec_print_error(redir->file_name));
		}
		else if (redir->type & DGREAT)
		{
			if ((fd = open(redir->file_name, O_WRONLY | O_CREAT | O_APPEND)) < 0)
				return (exec_print_error(redir->file_name));
		}
		dup2(fd, redir->io_number);
		close(fd);
	}
	if (redir->type & GREATAND)
		dup2(cmd->right_fd, cmd->left_fd);
	if (cmd->spec.bits.c)
		close(cmd->right_fd);
	return (0);
}


// int		exec_redir_right(t_attr *cmd)
// {
// 	int	fd;

// 	if (cmd->file && (fd = 1))
// 	{
// 		if (cmd->spec.bits.r)
// 		{
// 			if ((fd = open(cmd->file, O_WRONLY | O_CREAT | O_TRUNC)) < 0)
// 				return (exec_print_error(cmd->file));
// 		}
// 		else if (cmd->spec.bits.rr)
// 		{
// 			if ((fd = open(cmd->file, O_WRONLY | O_CREAT | O_APPEND)) < 0)
// 				return (exec_print_error(cmd->file));
// 		}
// 		dup2(fd, cmd->right_fd);
// 		close(fd);
// 	}
// 	if (cmd->spec.bits.rd)
// 		dup2(cmd->right_fd, cmd->left_fd);
// 	if (cmd->spec.bits.c)
// 		close(cmd->right_fd);
// 	return (0);
// }
