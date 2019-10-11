/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggwin-go <ggwin-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/17 22:04:36 by ggwin-go          #+#    #+#             */
/*   Updated: 2019/10/11 15:24:09 by gmelisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"
#include "hash.h"

#define FLAG_P					1
#define FLAG_N					2
#define FLAG_F					4

#define INVALID_OPTION			1

static void		print_usage(char c)
{
	print_error_vaarg("export: -%c: invalid option", c);
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

static int		print_export_error(const char *str)
{
	char		*error_msg;

	error_msg = ft_xstrjoin("'", str);
	error_msg = ft_strrejoin(error_msg, "': not a valid identifier", 1);
	print_error("export", error_msg);
	ft_strdel(&error_msg);
	return (1);
}

static void		export_var(const char *str, int opt)
{
	extern char	**environ;
	char		*p;
	const char	*tmp_var;

	if ((p = ft_strchr(str, '=')))
		set_var(str, &environ, 0);
	if (opt & FLAG_N)
		remove_var(str, &environ);
	else if (!p)
	{
		if ((p = get_var_value((char *)str)))
		{
			tmp_var = (const char *)ft_xstrjoin(str, "=");
			tmp_var = (const char *)ft_strrejoin(tmp_var, p, 1);
		}
		else
			tmp_var = (const char *)ft_xstrjoin(str, "=");
		set_var(tmp_var, &environ, 0);
		ft_strdel((char **)&tmp_var);
	}
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
			else if ((flag = 1) && *str == '-')
				res = print_export_error(str);
			else
				export_var(str, opt);
			++av;
		}
	if (!flag)
		print_vars(0);
	return (res);
}
