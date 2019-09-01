/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggwin-go <ggwin-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/17 22:04:36 by ggwin-go          #+#    #+#             */
/*   Updated: 2019/08/30 22:27:28 by ggwin-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"
#include "hash.h"

#define FLAG_P	1
#define FLAG_N	2
#define FLAG_F	4

static int		print_usage(void)
{
	extern char	**environ;

	(void)environ;
	return (1);
}

static int		add_flags(const char *str, int *opt)
{
	while (*(++str))
		if (*str == 'n')
			*opt |= FLAG_N;
		else if (*str == 'p')
			*opt |= FLAG_P;
		else if (*str == 'f')
			*opt |= FLAG_F;
		else
			return (print_usage());
	return (0);
}

static int		export_var(const char *str, int opt)
{
	extern char	**environ;

	if (*str == '-')
	{
		ft_putstr_fd(g_project_name, 2);
		ft_putstr_fd(": export: '", 2);
		ft_putstr_fd(str, 2);
		ft_putendl_fd("': not a valid identifier", 2);
		return (1);
	}
	(opt & FLAG_N) ? remove_var(str, &environ) : set_var(str, &environ, 0);
	return (0);
}

static void		print_exported_vars(void)
{
	(void)g_project_name;
}

int				ft_export(const char **av)
{
	const char	*str;
	int			flag;
	int			opt;

	flag = 0;
	opt = 0;
	if (*av)
		while ((str = *av))
		{
			if (!flag && *str == '-')
				add_flags(str, &opt);
			else
			{
				flag = 1;
				if (export_var(str, opt) == 1)
					return (1);
			}
			++av;
		}
	else if (opt & FLAG_P)
		print_exported_vars();
	return (0);
}
