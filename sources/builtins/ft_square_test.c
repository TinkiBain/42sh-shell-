/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_square_test.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wtalea <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 19:09:29 by wtalea            #+#    #+#             */
/*   Updated: 2019/10/13 19:39:42 by wtalea           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_test.h"

static	int	square_fill(const char **argv, int len)
{
	const char	*argv_cp[len];
	int			i;

	i = 0;
	while (i < (len - 1))
	{
		argv_cp[i] = (const char *)argv[i];
		++i;
	}
	argv_cp[i] = NULL;
	return (ft_test((char **)argv_cp));
}

static	int	square_print_error(void)
{
	write(STDERR, "[: ']' expected\n", 16);
	return (2);
}

int			ft_square_test(int argc, const char **argv)
{
	if (argc > 1)
	{
		if (!ft_strcmp(argv[argc - 1], "]"))
		{
			if (argc == 2)
				return (1);
			return (square_fill(argv + 1, argc - 1));
		}
		else
			return (square_print_error());
	}
	else
		return (square_print_error());
}
