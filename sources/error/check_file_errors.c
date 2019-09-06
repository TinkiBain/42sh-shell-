/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file_errors.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggwin-go <ggwin-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/29 19:26:54 by ggwin-go          #+#    #+#             */
/*   Updated: 2019/09/06 01:58:53 by ggwin-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

char	*get_str_line_num(void)
{
	extern int	g_line_num;
	char		*p;
	static char	res[32];

	ft_bzero(res, 32);
	if (!(p = ft_itoa(g_line_num)))
		die();
	ft_memcpy(res, "line ", 5);
	ft_memcpy(res + 5, p, ft_strlen(p));
	ft_strdel(&p);
	return (res);
}

int		check_file_errors(const char *file_name, int flag)
{
	struct stat		st;
	extern t_opt	g_opt;
	char			*error;

	if ((stat(file_name, &st) == -1 && (error = "No such file or directory"))
			|| (S_ISDIR(st.st_mode) && (error = "Is a directory"))
			|| (!S_ISREG(st.st_mode) && (error = "No such file or directory"))
			|| (access(file_name, flag) && (error = "Permission denied")))
	{
		if (g_opt.rl_in != 0)
			print_error_ext(error, get_str_line_num(), file_name);
		else
			print_error(error, file_name);
		return ((g_res_exec = 127));
	}
	return (0);
}
