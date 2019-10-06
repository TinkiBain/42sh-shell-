/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_test.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wtalea <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/31 15:21:14 by wtalea            #+#    #+#             */
/*   Updated: 2019/09/29 13:57:10 by wtalea           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_test.h"

static	int		check_minus(char **argv)
{
	if (*argv && *(argv + 1) && *(argv + 2))
	{
		test_too_many();
		return (2);
	}
	else if (*(*argv + 1) && !*(*argv + 2))
		return (test_find_flag(argv));
	else
	{
		test_unary(*argv);
		return (2);
	}
}

static	int		check_file(char **argv)
{
	if (**argv == '-')
	{
		return ((check_minus(argv)));
	}
	else
	{
		test_unary(*argv);
		return (2);
	}
	return (2);
}

static int		check_argv(char **argv)
{
	if (argv && *argv)
	{
		if (*argv && *(argv + 1) && !*(argv + 2))
			return (check_file(argv));
		else if (*argv && *(argv + 1) && *(argv + 2) &&
				!*(argv + 3))
			return (test_check_compare(argv));
		else if (*argv && *(argv + 1) && *(argv + 2)
				&& *(argv + 3))
		{
			test_too_many();
			return (2);
		}
	}
	return (0);
}

int				ft_test(char **argv)
{
	int		i;

	i = 0;
	if (argv && *(argv))
	{
		if (**argv)
		{
			if (**argv == '!')
			{
				i = check_argv(argv + 1);
				return ((i != 2) ? ((i - 1) * -1) : i);
			}
			else
				return (check_argv(argv));
		}
		else
		{
			test_unary(*argv);
			return (2);
		}
	}
	return (1);
}
