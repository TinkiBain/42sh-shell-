/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fc_edit_build_argv.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelisan <gmelisan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 20:35:07 by gmelisan          #+#    #+#             */
/*   Updated: 2019/10/07 20:47:18 by gmelisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fc.h"

static char	**have_e_arg(char *str)
{
	char	*name;
	char	**argv;

	name = g_optarg;
	if (!name)
		return (NULL);
	if (name[0] != '/')
		name = get_bin(name);
	if (!name)
	{
		print_error("command not found", g_optarg);
		return (NULL);
	}
	argv = ft_xmemalloc(sizeof(char *) * 3);
	argv[0] = ft_xstrdup(name);
	argv[1] = ft_xstrdup(str);
	return (argv);
}

char		**ft_fc_edit_build_argv(char *str, t_cmd_opt opt)
{
	char	*name;
	char	**argv;

	if (opt.e)
		return (have_e_arg(str));
	name = get_var_value("FCEDIT");
	if (!name)
		name = EDPATH;
	else if (name[0] != '/' &&
			!(name = get_bin(name)))
		get_var_value("FCEDIT");
	argv = ft_xmemalloc(sizeof(char *) * 3);
	argv[0] = ft_xstrdup(name);
	argv[1] = ft_xstrdup(str);
	return (argv);
}
