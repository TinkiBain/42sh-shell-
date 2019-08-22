/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history_load.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelisan </var/spool/mail/vladimir>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/21 18:36:32 by gmelisan          #+#    #+#             */
/*   Updated: 2019/08/21 18:47:26 by gmelisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "history.h"

static int	history_open(t_history *history)
{
	int		fd;
	char	*s_max;

	fd = -1;
	history->path = tdq(ft_xstrdup(get_value_from_all_vars("HISTPATH")));
	s_max = ft_xstrdup(get_value_from_all_vars("HISTSIZE"));
	history->max_size = s_max ? ft_atoi(s_max) : 0;
	ft_strdel(&s_max);
	if (history->path)
		fd = open(history->path, O_RDONLY | O_CREAT, S_IRWXU);
	if (fd < 0)
		loginfo("Can't open history file: %s", history->path);
	else
		loginfo("History location: %s", history->path);
	return (fd);
}


void		history_load(t_history *history)
{
	int			fd;
	t_string	str;
	int			ret;

	if ((fd = history_open(history)) < 0)
		return ;
	while ((ret = get_next_line(fd, &str.s)) > 0)
	{
		str_fixlen(&str);
		ft_dlstaddback(&history->item, ft_dlstnew(&str, sizeof(str)));
		history->size++;
	}
	if (ret < 0)
		loginfo("Error in history get_next_line()");
	while (history->size > history->max_size)
	{
		ft_dlstdelfront(&history->item, del_hist);
		history->size--;
	}
	close(fd);
}
