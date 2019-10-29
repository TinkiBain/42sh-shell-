/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_and_add_flags.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggwin-go <ggwin-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/29 16:01:23 by wtalea            #+#    #+#             */
/*   Updated: 2019/10/29 23:02:09 by ggwin-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hash.h"
#include <fcntl.h>
#include <dirent.h>
#include "sh.h"

static void		fill_arr(int fd, char ***arr)
{
	int			i;

	i = 0;
	while ((get_next_line(fd, (*arr + i))) > 0)
		++i;
	*(*arr + i) = NULL;
}

static void		read_and_fill(int fd, t_hash *table)
{
	char		*line;
	int			len;

	len = 0;
	while ((get_next_line(fd, &line)) > 0)
	{
		ft_strdel(&line);
		++len;
	}
	ft_strdel(&line);
	table->flags_args = (char **)ft_xmemalloc(sizeof(char *) * (len + 1));
	lseek(fd, 0, SEEK_SET);
	fill_arr(fd, &table->flags_args);
}

static void		find_args(const char *path, struct dirent *file)
{
	t_hash		*table;
	int			fd;
	char		*s;

	table = NULL;
	if (file)
		if ((table = get_hash_struct(file->d_name)))
		{
			s = ft_xstrjoin(path, "/");
			s = ft_xstrrejoin(s, table->name, 1);
			if ((fd = open(s, O_RDONLY)))
			{
				read_and_fill(fd, table);
				close(fd);
			}
			ft_strdel(&s);
		}
}

void			find_and_add_flags(const char *path)
{
	DIR				*dir;
	struct dirent	*file;

	dir = NULL;
	file = NULL;
	if ((dir = opendir(path)))
	{
		while ((file = readdir(dir)))
			find_args(path, file);
		closedir(dir);
	}
}

void			add_flags_args(void)
{
	char		*resources;
	int			fd;

	resources = NULL;
	fd = 0;
	if ((resources = get_var_value("SHELLHOME")))
	{
		resources = ft_xstrjoin(resources, "/resources/flags_args");
		find_and_add_flags(resources);
		ft_strdel(&resources);
	}
}
