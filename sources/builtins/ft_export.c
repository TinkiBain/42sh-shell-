/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggwin-go <ggwin-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/17 22:04:36 by ggwin-go          #+#    #+#             */
/*   Updated: 2019/10/13 23:23:51 by ggwin-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"
#include "hash.h"

#define FLAG_P					1
#define FLAG_N					2
#define FLAG_F					4

static int			check_and_add_flags(const char *str, int *opt)
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
			print_error_vaarg("export: -%c: invalid option", *str);
			ft_putendl_fd("export: usage: export [-nf] [name[=value] ...]"
														" or export -p", 2);
			return (1);
		}
	return (0);
}

static int			print_export_error(const char *str)
{
	char			*error_msg;

	error_msg = ft_xstrjoin("'", str);
	error_msg = ft_xstrrejoin(error_msg, "': not a valid identifier", 1);
	print_error("export", error_msg);
	ft_strdel(&error_msg);
	return (1);
}

static void			export_func_def(const char *str)
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
	set_var(tmp, &environ, 0);
	ft_strdel(&tmp);
}

static void			export_var(const char *str, int opt)
{
	extern char		**environ;
	char			*p;
	const char		*tmp_var;

	if ((p = ft_strchr(str, '=')))
		set_var(str, &environ, 0);
	if (opt & FLAG_N)
		remove_var(str, &environ);
	if (opt & FLAG_F)
		export_func_def(str);
	else if (!p)
	{
		if ((p = get_var_value((char *)str)))
		{
			tmp_var = (const char *)ft_xstrjoin(str, "=");
			tmp_var = (const char *)ft_xstrrejoin(tmp_var, p, 1);
		}
		else
			tmp_var = (const char *)ft_xstrjoin(str, "=");
		set_var(tmp_var, &environ, 0);
		ft_strdel((char **)&tmp_var);
	}
}

int					ft_export(const char **av)
{
	const char		*str;
	int				flag;
	int				opt;
	int				res;

	flag = 0;
	opt = 0;
	res = 0;
	if (*av)
		while ((str = *av))
		{
			if (!flag && *str == '-')
			{
				if (check_and_add_flags(str, &opt))
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
