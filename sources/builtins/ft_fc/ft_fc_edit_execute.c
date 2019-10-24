/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fc_edit_execute.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jterry <jterry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 20:33:42 by gmelisan          #+#    #+#             */
/*   Updated: 2019/10/24 20:29:00 by jterry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fc.h"

int			ft_fc_edit_execute(char *path, t_pjobs **local)
{
	char	*s;
	int		ret;
	int		fd;

	if ((fd = open(path, O_RDONLY, S_IRWXU | S_IRWXG | S_IRWXO)) < 0)
		loginfo("ft_fc(): open error (%s)", path);
	while ((ret = get_next_line(fd, &s)) > 0)
		if (*s)
		{
			ft_getopt_clear();
			ft_putendl_fd(s, STDERR);
			(*local) = jobs_started(ft_xstrdup(s), 0);
			call_subshell(s, local);
		}
		else
			ft_strdel(&s);
	if (ret == -1)
		loginfo("ft_fc(): gnl error (%s), fd = %d", path, fd);
	if (fd != -1)
		close(fd);
	return (ret);
}
