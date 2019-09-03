/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file_errors.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggwin-go <ggwin-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/29 19:26:54 by ggwin-go          #+#    #+#             */
/*   Updated: 2019/09/03 23:19:53 by gmelisan         ###   ########.fr       */
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

/* may be rework somehow later
 * Why it always return 127? */

int		return_error(const char *file_name, const char *error)
{
	extern char		**g_var;
	extern t_opt	g_opt;

	if (g_opt.rl_in != 0)
		print_error_ext(error, get_str_line_num(), file_name);
	else
		print_error(error, file_name);
	g_res_exec = 127;
	set_var("?=127", &g_var, 1);
	return (127);
}

int		check_file_errors(const char *file_name, int flag)
{
	struct stat		st;

	if (stat(file_name, &st) == -1)
		return (return_error(file_name, ": No such file or directory"));
	if (S_ISDIR(st.st_mode))
		return (return_error(file_name, ": Is a directory"));
	else if (!S_ISREG(st.st_mode))
		return (return_error(file_name, ": No such file or directory"));
	else if (access(file_name, flag))
		return (return_error(file_name, ": Permission denied"));
	return (0);
}
