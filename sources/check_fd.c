/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_fd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggwin-go <ggwin-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/17 16:21:00 by dwisoky           #+#    #+#             */
/*   Updated: 2019/08/24 20:46:37 by ggwin-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdlib.h>
#include "exec.h"

void			preliminary_check_fd(void)
{
	if (fcntl(0, F_GETFL) < -1)
		exit(0);
	if (!isatty(0))
	{
		exit(g_res_exec);
	}
}
