/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fc_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelisan <gmelisan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 18:39:53 by gmelisan          #+#    #+#             */
/*   Updated: 2019/10/07 18:08:15 by gmelisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fc.h"

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
		*pp_last = ft_fc_find_arg_number("-1");
	}
	else
	{
		*pp_first = ft_fc_find_arg_number("-16");
		*pp_last = ft_fc_find_arg_number("-1");
	}
	if (!*pp_first || !*pp_last)
		print_error("history specification out of range", "fc");
}

int				ft_fc_list(const char **argv, t_cmd_opt opt)
{
	t_vector	vec;
	int			i;
	t_string	*s;
	int			start;

	vec = ft_fc_build_vector(argv, &start, opt, get_first_last);
	i = (opt.r ? vec.len - 1 : 0);
	while ((s = vec_get(vec, i)))
	{
		if (opt.n)
			ft_printf("\t%s\n", s->s);
		else
			ft_printf("%d\t%s\n", ft_abs(start), s->s);
		i = (opt.r ? i - 1 : i + 1);
		start = (opt.r ? start - 1 : start + 1);
	}
	ft_memdel(&vec.v);
	if (vec.len == 0)
		return (1);
	return (0);
}
