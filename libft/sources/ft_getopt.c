/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getopt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelisan <gmelisan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 18:57:13 by gmelisan          #+#    #+#             */
/*   Updated: 2019/09/14 18:28:59 by gmelisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*g_optarg;
int			g_optind = 1;
int			g_optpos = 1;
int			g_optopt;
int			g_opterr = 1;
char		*g_opterrpref;

static void	update_indpos(char *const argv[])
{
	if (argv[g_optind][g_optpos + 1] == '\0')
	{
		g_optind++;
		g_optpos = 1;
	}
	else
		g_optpos += 1;
}

static int	found(int argc, char *const argv[], char *f)
{
	g_optarg = NULL;
	if (*(f + 1) == ':')
	{
		if (argv[g_optind][g_optpos + 1] == '\0')
		{
			g_optarg = argv[g_optind + 1];
			g_optind += 2;
			g_optpos = 1;
			if (g_optind > argc && g_opterr)
				ft_fdprintf(2, "%s-%c: option requires an argument\n",
							g_opterrpref ? g_opterrpref : "", g_optopt);
			return (g_optind > argc ? '?' : g_optopt);
		}
		else
		{
			g_optarg = &argv[g_optind][g_optpos + 1];
			g_optind += 1;
			g_optpos = 1;
			return (g_optopt);
		}
	}
	update_indpos(argv);
	return (g_optopt);
}

static int	not_found(char *const argv[])
{
	update_indpos(argv);
	ft_fdprintf(2, "%s-%c: invalid option\n",
				g_opterrpref ? g_opterrpref : "", g_optopt);
	return ('?');
}

int			ft_getopt(int argc, char *const argv[], const char *optstring)
{
	char		*f;

	if (!optstring || !argv[g_optind] || g_optind > argc - 1
		|| *argv[g_optind] != '-' || ft_strequ(argv[g_optind], "-"))
		return (-1);
	if ((g_optopt = argv[g_optind][g_optpos]))
	{
		if (ft_strequ(argv[g_optind], "--"))
		{
			g_optind++;
			return (-1);
		}
		if ((f = ft_strchr(optstring, g_optopt)))
			return (found(argc, argv, f));
		else
			return (not_found(argv));
	}
	return (-1);
}
