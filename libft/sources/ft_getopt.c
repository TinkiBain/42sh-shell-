/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getopt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelisan <gmelisan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 18:57:13 by gmelisan          #+#    #+#             */
/*   Updated: 2019/09/13 18:57:41 by gmelisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*g_optarg;
int			g_optind = 1;
int			g_optopt;

static void	update_indpos(char *const argv[], int *pos)
{
	if (argv[g_optind][*pos + 1] == '\0')
	{
		g_optind++;
		*pos = 1;
	}
	else
		*pos += 1;
}

static int	found(int argc, char *const argv[], char *f, int *pos)
{
	g_optarg = NULL;
	if (*(f + 1) == ':')
	{
		if (argv[g_optind][*pos + 1] == '\0')
		{
			g_optarg = argv[g_optind + 1];
			g_optind += 2;
			*pos = 1;
			return (g_optind > argc ? '?' : g_optopt);
		}
		else
		{
			g_optarg = &argv[g_optind][*pos + 1];
			g_optind += 1;
			*pos = 1;
			return (g_optopt);
		}
	}
	update_indpos(argv, pos);
	return (g_optopt);
}

static int	not_found(char *const argv[], int *pos)
{
	update_indpos(argv, pos);
	return ('?');
}

int			ft_getopt(int argc, char *const argv[], const char *optstring)
{
	static int	pos = 1;
	char		*f;

	if (!optstring || !argv[g_optind] || g_optind > argc - 1
		|| *argv[g_optind] != '-' || ft_strequ(argv[g_optind], "-"))
		return (-1);
	if ((g_optopt = argv[g_optind][pos]))
	{
		if (ft_strequ(argv[g_optind], "--"))
		{
			g_optind++;
			return (-1);
		}
		if ((f = ft_strchr(optstring, g_optopt)))
			return (found(argc, argv, f, &pos));
		else
			return (not_found(argv, &pos));
	}
	return (-1);
}
