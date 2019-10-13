/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggwin-go <ggwin-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/17 22:04:36 by ggwin-go          #+#    #+#             */
/*   Updated: 2019/10/13 23:31:46 by ggwin-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"
#include "hash.h"

extern char			**g_var;
extern t_dict		*g_func_defs;

static void			remove_func_def(const char *str)
{
	extern t_dict	*g_func_defs;
	extern char		**environ;
	t_dict			*func;
	char			*tmp;

	if (!(func = ft_get_dict(g_func_defs, str)))
		return ;
	tmp = ft_xstrjoin("BASH_FUNC_", str);
	tmp = ft_xstrrejoin(tmp, "%%=() { ", 1);
	tmp = ft_xstrrejoin(tmp, func->value, 1);
	tmp = ft_xstrrejoin(tmp, "\n}", 1);
	remove_var(tmp, &g_var);
	remove_var(tmp, &environ);
	ft_strdel(&tmp);
	ft_dict_remove_elem(&g_func_defs, func);
	fill_g_cmd_names();
}

int					ft_unset(const char **av)
{
	size_t			len;
	extern char		**environ;
	int				flag;

	if (!g_var)
		return (1);
	flag = (ft_strequ(*av, "-f") && *(++av)) ? 1 : 0;
	while (*av)
	{
		len = ft_strlen(*av);
		if (flag && g_func_defs)
			remove_func_def(*av);
		else if (!check_readonly_var(*av, len))
		{
			remove_var(*av, &g_var);
			remove_var(*av, &environ);
			if (len == 4 && ft_strnequ(*av, "PATH", 4))
				fill_hash_table();
		}
		++av;
	}
	return (0);
}
