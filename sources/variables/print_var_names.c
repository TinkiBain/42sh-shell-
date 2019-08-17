/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_var_names.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggwin-go <ggwin-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/17 23:30:40 by ggwin-go          #+#    #+#             */
/*   Updated: 2019/08/17 23:34:23 by ggwin-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int				print_var_names(void)
{
	extern char	**g_var_names;
	char		**tmp;

	tmp = g_var_names;
	while (*tmp)
		ft_putendl(*(tmp++));
	return (0);
}
