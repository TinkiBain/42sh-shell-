/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_and_add_flags.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wtalea <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/29 16:01:23 by wtalea            #+#    #+#             */
/*   Updated: 2019/10/13 12:21:29 by wtalea           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hash.h"
#include <fcntl.h>
#include <dirent.h>
#include "sh.h"

static	void	fill_arr(int fd, char ***arr)
{
	int		i;

	i = 0;
	while ((get_next_line(fd, (*arr + i))))
		++i;
	*(*arr + i) = NULL;
}

static	void	read_and_fill(int fd, t_hash *table)
{
	char		*line;
	int			len;

	len = 0;
	while ((get_next_line(fd, &line)))
	{
		free(line);
		++len;
	}
	table->flags_args = (char **)xmalloc(sizeof(char *) * (len + 1));
	lseek(fd, 0, SEEK_SET);
	fill_arr(fd, &table->flags_args);
}

static	void	find_args(int fd_dir, struct dirent *file)
{
	t_hash		*table;
	int			fd;

	table = NULL;
	fd = 0;
	if (file)
		if ((table = get_hash_struct(file->d_name)))
			if ((fd = openat(fd_dir, table->name, O_RDONLY)))
				read_and_fill(fd, table);
}

void			find_and_add_flags(int fd)
{
	DIR				*dir;
	struct dirent	*file;

	dir = NULL;
	file = NULL;
	if ((dir = fdopendir(fd)))
	{
		while ((file = readdir(dir)))
			find_args(fd, file);
		closedir(dir);
	}
}

void			add_flags_args(void)
{
	char	*resources;
	int		fd;

	resources = NULL;
	fd = 0;
	if ((resources = get_var_value("SHELLHOME")))
	{
		resources = ft_xstrjoin(resources, "/resources/flags_args");
		if ((fd = openat(fd, resources, O_RDONLY)))
			find_and_add_flags(fd);
		free(resources);
	}
}
