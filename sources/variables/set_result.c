/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_result.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggwin-go <ggwin-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/27 14:58:08 by ggwin-go          #+#    #+#             */
/*   Updated: 2019/09/03 23:07:41 by ggwin-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

void	set_result(void)
{
	extern char	**g_var;
	char		*tmp;
	int			res;

	if (WIFEXITED(g_res_exec))
		res = WEXITSTATUS(g_res_exec);
	else
		res = g_res_exec;
	tmp = ft_strrejoin("?=", ft_itoa(res), 2);
	set_var(tmp, &g_var, 1);
	ft_memdel((void **)&tmp);
}
