/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggwin-go <ggwin-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 22:35:39 by gmelisan          #+#    #+#             */
/*   Updated: 2019/09/21 17:44:05 by gmelisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error.h"
#include "sem.h"

void		print_error(const char *msg, const char *info)
{
	extern t_opt	g_opt;
	extern int		g_line_num;

	reserve_sem();
	ft_fdprintf(STDERR, "%s: ", g_project_name);
	if (g_opt.rl_gnl != 0)
		ft_fdprintf(STDERR, "line %d: ", g_line_num);
	if (info)
		ft_fdprintf(STDERR, "%s: ", info);
	ft_fdprintf(STDERR, "%s\n\r", msg);
	loginfo("! Error: %s (\"%s\")", msg, info);
	release_sem();
}

void	print_error_exit(const char *msg, const char *info, const int code)
{
	print_error(msg, info);
	logclose();
	exit(code);
}
