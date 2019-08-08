/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggwin-go <ggwin-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/17 22:03:12 by ggwin-go          #+#    #+#             */
/*   Updated: 2019/08/08 13:20:17 by ggwin-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

int		ft_env(const char **av, char **env)
{
	char	**arr;
	char	**tmp;

	if (!env)
		return (1);
	if (*av == NULL)
		while (*env)
			ft_putendl(*(env++));
	else
	{
		if (ft_strequ("-s", *av))
		{
			arr = ft_sort_str_array(env, 0);
			tmp = arr;
			while (*arr)
				ft_putendl(*(arr++));
			ft_free_double_ptr_arr((void ***)&tmp);
		}
	}
	return (0);
}
