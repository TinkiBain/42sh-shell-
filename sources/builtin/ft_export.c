/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggwin-go <ggwin-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/17 22:04:36 by ggwin-go          #+#    #+#             */
/*   Updated: 2019/09/07 18:25:22 by ggwin-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"
#include "hash.h"

#define FLAG_P					1
#define FLAG_N					2
#define FLAG_F					4

#define NOT_A_VALID_IDENTIFIER	1
#define INVALID_OPTION			2

static void		print_usage(char c)
{
	ft_putstr_fd(g_project_name, 2);
	ft_putstr_fd(": export: -", 2);
	ft_putchar_fd(c, 2);
	ft_putendl_fd(": invalid option", 2);
	ft_putendl_fd("export: usage: export [-nf] [name[=value] ...]"
														" or export -p", 2);
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
		{
			print_usage(*str);
			return (INVALID_OPTION);
		}
	return (0);
}

static int		export_var(const char *str, int opt)
{
	extern char	**environ;
	char		*p;
	const char	*tmp_var;

	if (*str == '-')
	{
		ft_putstr_fd(g_project_name, 2);
		ft_putstr_fd(": export: '", 2);
		ft_putstr_fd(str, 2);
		ft_putendl_fd("': not a valid identifier", 2);
		return (1);
	}
	if ((p = ft_strchr(str, '=')))
		set_var(str, &environ, 0);
	if (opt & FLAG_N)
		remove_var(str, &environ);
	else if (!p)
	{
		if ((p = get_var_value((char *)str)))
		{
			tmp_var = (const char *)ft_strjoin(str, "=");
			tmp_var = (const char *)ft_strrejoin(tmp_var, p, 1);
		}
		else
			tmp_var = (const char *)ft_strjoin(str, "=");
		set_var(tmp_var, &environ, 0);
		ft_strdel((char **)&tmp_var);
	}
	return (0);
}

int				ft_export(const char **av)
{
	const char	*str;
	int			flag;
	int			opt;
	int			res;

	flag = 0;
	opt = 0;
	res = 0;
	if (*av)
		while ((str = *av))
		{
			if (!flag && *str == '-')
			{
				if (add_flags(str, &opt) == INVALID_OPTION)
					return (2);
			}
			else if ((flag = 1) &&
							(export_var(str, opt) == NOT_A_VALID_IDENTIFIER))
				res = NOT_A_VALID_IDENTIFIER;
			++av;
		}
	if (!flag)
		print_all_vars(0);
	return (res);
}
