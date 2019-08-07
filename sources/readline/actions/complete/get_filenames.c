/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_filenames.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelisan <gmelisan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/07 21:35:15 by gmelisan          #+#    #+#             */
/*   Updated: 2019/08/07 22:11:20 by gmelisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "actions.h"

static int		match(t_string name, t_string query)
{
	int i;

	i = -1;
	while (str_get(query, ++i))
	{
		if (str_get(name, i) != str_get(query, i))
			return (0);
	}
	return (1);
}

static t_vector	build(DIR *dir, t_string *query)
{
	struct dirent	*ent;
	t_string		name;
	t_vector		vec;

	vec = vec_xcreate(0, sizeof(t_string));
	while (dir && (ent = readdir(dir)))
	{
		name = str_xcopy(ent->d_name);
		if (match(name, *query))
			vec_xaddback(&vec, &name);
	}
	str_delete(query);
	return (vec);
}

static t_vector	build_filenames_vector(t_string str, int *start)
{
	DIR			*dir;
	t_string	path;
	t_string	query;
	char		c;
	int			i;

	path = str_xcreate(0);
	query = str_xcreate(0);
	i = str.len;
	while ((c = str_get(str, --i)) && c != '/')
		str_xaddfront(&query, &c, 1);
	i++;
	if (start)
		*start = i;
	while ((c = str_get(str, --i)))
		str_xaddfront(&path, &c, 1);
	if (path.len == 0)
		str_xaddfront(&path, ".", 1);
	dir = opendir(path.s);
	str_delete(&path);
	return (build(dir, &query));
}

t_vector		get_filenames(t_line *line, int *start)
{
	t_string	str;
	t_vector	vec;
	int			i;

	i = line->cpos - 1;
	while (str_get(*line->str, i) && !ft_isspace(str_get(*line->str, i)))
		i--;
	str = str_xsubstring(*line->str, i + 1, line->cpos);
	vec = build_filenames_vector(str, start);
	return (vec);
}
