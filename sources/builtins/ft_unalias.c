/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unalias.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwisoky <dwisoky@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 18:38:37 by dwisoky           #+#    #+#             */
/*   Updated: 2019/11/01 18:39:03 by dwisoky          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

extern t_alias	*g_alias;

int		alias_free_all(void)
{
	t_alias			*tmp;

	while (g_alias)
	{
		if (g_alias->head)
			free(g_alias->head);
		if (g_alias->body_alias)
			free(g_alias->body_alias);
		tmp = g_alias->next;
		free(g_alias);
		g_alias = tmp;
	}
	g_alias = NULL;
	return (0);
}

int		unalias_delete_one(const char *str, t_alias *alias)
{
	t_alias			*tmp;
	extern t_alias	*g_alias;

	tmp = NULL;
	while (alias)
	{
		if (ft_strequ(alias->head, str))
		{
			free(alias->head);
			if (alias->body_alias)
				free(alias->body_alias);
			if (tmp)
				tmp->next = alias->next;
			else
				g_alias = alias->next;
			free(alias);
			return (0);
		}
		tmp = alias;
		alias = alias->next;
	}
	return (1);
}

int		unalias_check_flag(const char *str)
{
	if (*str == '-')
		++str;
	else
		return (0);
	while (*str)
	{
		if (*str == 'a')
			++str;
		else
		{
			print_error_vaarg("unalias: -%c: invalid option\n", *str);
			ft_putstr_fd("unalias: usage: unalias [-a] name [name ...]\n", 2);
			return (-1);
		}
	}
	return (1);
}

int		ft_unalias(const char **av)
{
	extern t_alias	*g_alias;
	int				flag;
	int				tmp;
	int				return_value;

	return_value = 0;
	if (!*av)
	{
		ft_putstr_fd("unalias: usage: unalias [-a] name [name ...]\n", 2);
		return (1);
	}
	flag = unalias_check_flag(*av);
	if (flag == -1)
		return (1);
	if (flag)
		return (alias_free_all());
	while (*av)
	{
		tmp = unalias_delete_one(*av, g_alias);
		if (tmp)
			return_value = tmp;
		++av;
	}
	fill_g_cmd_names();
	return (return_value);
}
