/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggwin-go <ggwin-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/03 14:22:58 by ggwin-go          #+#    #+#             */
/*   Updated: 2019/10/30 22:51:41 by ggwin-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

static int	res_for_cmd_not_found(const char *cmd)
{
	print_error_vaarg("type: %s: not found\n", cmd);
	return (1);
}

static void	print_bin_path(const char *cmd, char *path)
{
	char	*s;

	if (path)
	{
		s = ft_xstrjoin(cmd, " is hashed (");
		s = ft_xstrrejoin(s, path, 1);
		s = ft_xstrrejoin(s, ")", 1);
	}
	else
		s = ft_xstrjoin(cmd, " is a shell builtin");
	ft_putendl(s);
	ft_strdel(&s);
}

int			ft_type(const char **av)
{
	char	*path;
	int		res;

	res = 0;
	if (av)
		while (*av)
		{
			if (is_builtin((char *)*av))
			{
				print_bin_path(*av, NULL);
				res = 1;
			}
			else if ((path = get_bin((char *)*av)))
			{
				print_bin_path(*av, path);
				res = 1;
			}
			else
				res = res_for_cmd_not_found(*av);
			++av;
		}
	return (res);
}
