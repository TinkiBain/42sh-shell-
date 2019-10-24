/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filter_filenames.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jterry <jterry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/07 21:35:15 by gmelisan          #+#    #+#             */
/*   Updated: 2019/10/24 21:08:58 by jterry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "actions.h"
#include <sys/stat.h>

static int		match(t_string name, t_string query)
{
	int			i;

	i = -1;
	while (str_get(query, ++i))
	{
		if (str_get(name, i) != str_get(query, i))
			return (0);
	}
	return (1);
}

static void		add_one(t_vector *vec, t_string *query,
						t_string *path, char *name)
{
	struct stat		st;
	t_string		fullpath;
	t_string		str_name;

	if (ft_strequ(name, ".") || ft_strequ(name, ".."))
		return ;
	fullpath = str_xduplicate(*path);
	str_name = str_xcopy(name);
	str_xaddback(&fullpath, str_name.s, str_name.len);
	ft_bzero(&st, sizeof(st));
	if (stat(fullpath.s, &st) == -1)
		loginfo("! stat(\"%s\", &st) returned -1", fullpath.s);
	str_delete(&fullpath);
	if ((st.st_mode & S_IFMT) == S_IFDIR)
		str_xaddback(&str_name, "/", 1);
	else
		str_xaddback(&str_name, " ", 1);
	if (match(str_name, *query))
		vec_xaddback(vec, &str_name.s);
	else
		str_delete(&str_name);
}

static t_vector	build(DIR *dir, t_string *query, t_string *path)
{
	struct dirent	*ent;
	t_vector		vec;

	vec = vec_xcreate(0, sizeof(char *));
	if (!dir)
		return (vec);
	str_xaddback(path, "/", 1);
	while (dir && (ent = readdir(dir)))
		add_one(&vec, query, path, ent->d_name);
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
	complete_unescape(&query);
	i++;
	while ((c = str_get(str, --i)) && !complete_isspace_check(str, i))
		str_xaddfront(&path, &c, 1);
	path.s = tdq(path.s, NULL);
	str_fixlen(&path);
	if (path.len == 0)
		str_xaddfront(&path, ".", 1);
	dir = opendir(path.s);
	return (build(dir, &query, &path));
}

t_vector		filter_filenames(t_line *line)
{
	t_string	str;
	t_vector	vec;
	int			i;

	i = line->cpos - 1;
	while (str_get(*line->str, i) && !complete_isspace_check(*line->str, i))
		i--;
	++i;
	str = str_xsubstring(*line->str, i, line->cpos - i);
	vec = build_filenames_vector(str);
	str_delete(&str);
	ft_qsort(vec.v, vec.len, vec.size, cmp_pstring);
	return (vec);
}
