/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fc_reexec.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggwin-go <ggwin-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/27 16:13:18 by gmelisan          #+#    #+#             */
/*   Updated: 2019/10/07 17:25:58 by ggwin-go         ###   ########.fr       */
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
	what = str_xncopy(arg, i);
	with = str_xcopy(arg + i + 1);
	i = 0;
	if (!ft_strstr(result.s, what.s))
		return (result.s);
	replace(&result, what, with);
	str_delete(&what);
	str_delete(&with);
	return (result.s);
}

static int	execute(const char *replace, t_dlist *item, t_pjobs *local)
{
	char		*exec_str;
	t_string	*item_str;

	exec_str = replace_if_need(replace, (t_string *)item->content);
	ft_dlst2end(&item);
	item_str = (t_string *)item->content;
	str_remove(item_str, 0, item_str->len);
	str_addback(item_str, exec_str, ft_strlen(exec_str));
	ft_putendl(exec_str);
	ft_getopt_clear();
	call_subshell(exec_str, local);
	return (g_res_exec);
}

int			ft_fc_reexec(const char **argv, t_pjobs *local)
{
	t_dlist		*item;
	const char	*replace;

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
	if (!item)
	{
		print_error("no command found", "fc");
		return (1);
	}
	return (execute(replace, item, local));
}
