/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggwin-go <ggwin-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/17 22:04:36 by ggwin-go          #+#    #+#             */
/*   Updated: 2019/10/12 20:14:08 by ggwin-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"
#include "hash.h"

int					ft_unset(const char **av)
{
	extern char		**g_var;
	extern char		**environ;
	extern t_dict	*g_func_defs;
	size_t			len;
	int				flag;

	if (!g_var)
		return (1);
	flag = (ft_strequ(*av, "-f") && *(++av)) ? 1 : 0;
	while (*av)
	{
		len = ft_strlen(*av);
		if (flag && g_func_defs)
		{
			ft_dict_remove_elem(&g_func_defs, ft_get_dict(g_func_defs, *av));
			fill_g_cmd_names();
		}
		else if (!check_readonly_var(*av, len))
		{
			remove_var(*av, &g_var);
			remove_var(*av, &environ);
			if (len == 4 && ft_strnequ(*av, "PATH", 4))
				fill_hash_table();
		}
		++av;
	}
	return (1);
}
