/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fc_edit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelisan <gmelisan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/03 18:51:07 by gmelisan          #+#    #+#             */
/*   Updated: 2019/11/02 20:02:43 by gmelisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fc.h"
#include "hash.h"

static void		get_first_last(const char **argv,
									t_dlist **pp_first, t_dlist **pp_last)
{
	if (!pp_first || !pp_last)
		return ;
	if (argv[g_optind] && argv[g_optind + 1])
	{
		*pp_first = ft_fc_find_arg(argv[g_optind]);
		*pp_last = ft_fc_find_arg(argv[g_optind + 1]);
	}
	else if (argv[g_optind])
	{
		*pp_first = ft_fc_find_arg(argv[g_optind]);
		*pp_last = *pp_first;
	}
	else
	{
		*pp_first = ft_fc_find_arg_number("-1");
		*pp_last = *pp_first;
	}
	if (!*pp_first || !*pp_last)
		print_error("fc", "history specification out of range");
}

static int		write_file(char *path, t_vector vec)
{
	int			i;
	int			fd;
	t_string	*str;

	if ((fd = open(path, O_RDWR | O_CREAT | O_TRUNC,
								S_IRWXU | S_IRWXG | S_IRWXO)) < 0)
	{
		loginfo("ft_fc(): open error (%s)", path);
		return (1);
	}
	i = -1;
	while ((str = vec_get(vec, ++i)))
		ft_putendl_fd(str->s, fd);
	close(fd);
	return (0);
}

static int		clear(t_vector vec, char **argv, int ret)
{
	free(vec.v);
	if (argv)
	{
		ft_strdel(&argv[0]);
		ft_strdel(&argv[1]);
		free(argv);
	}
	return (ret);
}

int				ft_fc_edit(const char **fc_argv, t_cmd_opt opt, t_pjobs **local)
{
	t_vector	vec;
	int			start;
	char		**argv;

	vec = ft_fc_build_vector(fc_argv, &start, opt, get_first_last);
	if (vec.len == 0 || write_file(TMP_PATH, vec) != 0)
		return (clear(vec, NULL, 1));
	if (!(argv = ft_fc_edit_build_argv(TMP_PATH, opt)))
		return (1);
	if (access(argv[0], X_OK) == -1)
		return (clear(vec, argv, 1));
	if (ft_fc_edit_run_editor(argv, local) != 0)
		return (clear(vec, argv, 1));
	if (ft_fc_edit_execute(TMP_PATH, local) != 0)
		return (clear(vec, argv, 1));
	unlink(TMP_PATH);
	return (clear(vec, argv, 0));
}
