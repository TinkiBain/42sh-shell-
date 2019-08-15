/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_filenames.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelisan <gmelisan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/07 21:35:15 by gmelisan          #+#    #+#             */
/*   Updated: 2019/08/15 01:49:59 by gmelisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "actions.h"
#include <sys/stat.h>

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

static t_vector	build(DIR *dir, t_string *query, t_string *path)
{
	struct dirent	*ent;
	struct stat		st;
	t_string		fullpath;
	t_string		name;
	t_vector		vec;

	str_xaddback(path, "/", 1);
	vec = vec_xcreate(0, sizeof(t_string));
	while (dir && (ent = readdir(dir)))
	{
		if (ft_strequ(ent->d_name, ".") || ft_strequ(ent->d_name, ".."))
			continue ;
		name = str_xcopy(ent->d_name);
		fullpath = str_xduplicate(*path);
		str_xaddback(&fullpath, name.s, name.len);
		stat(fullpath.s, &st);
		str_delete(&fullpath);
		if ((st.st_mode & S_IFMT) == S_IFDIR)
			str_xaddback(&name, "/", 1);
		else
			str_xaddback(&name, " ", 1);
		if (match(name, *query))
			vec_xaddback(&vec, &name);
		else
			str_delete(&name);
	}
	str_delete(query);
	str_delete(path);
	closedir(dir);
	return (vec);
}

static t_vector	build_filenames_vector(t_string str)
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
	while ((c = str_get(str, --i)) && !ft_isspace(c))
		str_xaddfront(&path, &c, 1);
	if (path.len == 0)
		str_xaddfront(&path, ".", 1);
	dir = opendir(path.s);
	return (build(dir, &query, &path));
}

t_vector		get_filenames(t_line *line)
{
	t_string	str;
	t_vector	vec;
	int			i;

	i = line->cpos - 1;
	while (str_get(*line->str, i) && !ft_isspace(str_get(*line->str, i)))
		i--;
	++i;
	str = str_xsubstring(*line->str, i, line->cpos - i);
	vec = build_filenames_vector(str);
	str_delete(&str);
	ft_qsort(vec.v, vec.len, vec.size, cmp);
	return (vec);
}
