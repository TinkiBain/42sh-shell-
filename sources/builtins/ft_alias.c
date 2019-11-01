/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_alias.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwisoky <dwisoky@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 20:24:42 by dwisoky           #+#    #+#             */
/*   Updated: 2019/11/01 18:42:29 by dwisoky          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

extern t_alias		*g_alias;

static t_alias		*alias_init(char *head, char *body)
{
	t_alias		*list;

	list = (t_alias*)ft_xmemalloc(sizeof(t_alias));
	list->head = head;
	list->body_alias = body;
	return (list);
}

static int			alias_set_str(const char *str, t_alias **alias)
{
	char			*head;
	char			*body;

	if (*str == '=' || !(body = ft_strchr(str, '=')))
		return (0);
	head = ft_xstrndup(str, body - str);
	if (ft_strchr(head, '/'))
	{
		print_error_vaarg("alias: `%s': invalid alias name\n", head);
		free(head);
		return (0);
	}
	body = ft_xstrdup(body + 1);
	while (*alias)
		if (ft_strequ(head, (*alias)->head))
		{
			free(head);
			free((*alias)->body_alias);
			(*alias)->body_alias = body;
			return (1);
		}
		else
			alias = &(*alias)->next;
	*alias = alias_init(head, body);
	return (1);
}

static int			alias_print_str(const char *str)
{
	t_alias			*tmp;

	tmp = g_alias;
	while (tmp)
	{
		if (ft_strequ(tmp->head, str))
		{
			ft_putstr("alias ");
			ft_putstr(tmp->head);
			ft_putstr("='");
			ft_putstr(tmp->body_alias);
			ft_putstr("'\n");
			return (0);
		}
		tmp = tmp->next;
	}
	print_error_vaarg("alias: %s: not found\n", str);
	return (1);
}

static const char	**check_flag(const char **av, int *return_value)
{
	const char	*tmp;

	if ((!*av || ft_strequ(*av, "-")))
		return (av);
	tmp = *av;
	if (ft_strequ(tmp, "--"))
		return (av + 1);
	if (*tmp != '-')
		return (av);
	++tmp;
	while (*tmp)
	{
		if (ft_strequ(tmp, "p"))
			return (NULL);
		if (*tmp != 'p')
		{
			print_error_vaarg("alias: -%c: invalid option\n", *tmp);
			ft_putendl_fd("alias: usage: alias [-p] [name[=value] ... ]", 2);
			*return_value = 1;
			return (NULL);
		}
		++tmp;
	}
	return (av + 1);
}

int					ft_alias(const char **av)
{
	t_alias			*tmp_alias;
	int				return_value;
	int				tmp;

	tmp = 0;
	tmp_alias = g_alias;
	return_value = 0;
	av = check_flag(av, &return_value);
	if (!av || !*av)
		while (tmp_alias)
		{
			alias_print_str(tmp_alias->head);
			tmp_alias = tmp_alias->next;
		}
	while (av && *av)
	{
		if (!(tmp = alias_set_str(*av, &g_alias)))
			tmp = alias_print_str(*av);
		if (!return_value)
			return_value = tmp;
		++av;
	}
	fill_g_cmd_names();
	return (return_value);
}
