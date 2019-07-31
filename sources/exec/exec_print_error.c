/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_print_error.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggwin-go <ggwin-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/04 20:47:06 by dwisoky           #+#    #+#             */
/*   Updated: 2019/07/30 14:20:53 by ggwin-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

int		exec_print_error(char *str)
{
	ft_putstr_fd(PROJECT_NAME, 2);
	ft_putstr_fd(": ", 2);
	perror(str);
	return (-1);
}
