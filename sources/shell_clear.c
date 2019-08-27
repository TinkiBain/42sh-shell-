/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_clear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelisan <gmelisan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/27 01:25:17 by gmelisan          #+#    #+#             */
/*   Updated: 2019/08/27 01:50:45 by gmelisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

void		shell_clear(void)
{
	extern char	**environ;

	del_hash();
	history_clear(g_history);
	logclose();
	ft_free_double_ptr_arr((void ***)&environ);
	ft_putstr("exit\n");
}
