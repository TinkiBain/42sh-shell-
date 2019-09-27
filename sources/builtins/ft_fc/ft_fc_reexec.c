/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fc_reexec.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelisan <gmelisan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/27 16:13:18 by gmelisan          #+#    #+#             */
/*   Updated: 2019/09/27 17:42:27 by gmelisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fc.h"

static void	replace(t_string *result, t_string what, t_string with)
{
	char	*found;
	int		i;

	if (!(found = ft_strstr(result->s, what.s)))
		return ;
	i = 0;
	while (result->s + i != found)
		i++;
	str_remove(result, i, what.len);
	str_xinsert(result, i, with.s, with.len);
}

static char	*replace_if_need(const char *arg, t_string *str)
{
	int			i;
	t_string	what;
	t_string	with;
	t_string	result;

	result = str_xduplicate(*str);
	if (!arg)
		return (result.s);
	i = 0;
	while (arg[i] && arg[i] != '=')
		i++;
	if (!arg[i])
		return (result.s);
	what = str_xncopy((char *)arg, i);
	with = str_xcopy((char *)arg + i + 1);
	i = 0;
	if (!ft_strstr(result.s, what.s))
		return (result.s);
	replace(&result, what, with);
	str_delete(&what);
	str_delete(&with);
	return (result.s);		
}

int		ft_fc_reexec(const char **argv, t_cmd_opt opt)
{
	t_dlist		*item;
	char		*exec_str;
	const char	*replace;
	int			res;

	res = 0;
	replace = NULL;
	if (ft_strchr(argv[g_optind], '='))
	{
		replace = argv[g_optind];
		g_optind++;
	}
	if (argv[g_optind])
		item = ft_fc_find_arg(argv[g_optind]);
	else
		item = ft_fc_find_arg_number("-1");
	exec_str = replace_if_need(replace, (t_string *)item->content);
	//ft_putstr("To be exec: ");
	ft_putendl(exec_str);
	//res = execute_line(exec_str);
	ft_strdel(&exec_str);
	if (opt.s)
		return (res);
	return (res);
}
