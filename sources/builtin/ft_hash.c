/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hash.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggwin-go <ggwin-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/26 22:32:39 by ggwin-go          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2019/08/24 16:45:03 by wtalea           ###   ########.fr       */
=======
/*   Updated: 2019/08/24 21:53:23 by ggwin-go         ###   ########.fr       */
>>>>>>> dev
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"
#include "hash.h"

<<<<<<< HEAD
/*// static void	print_commands(t_list *head, const char *k)
// {
// 	while (head)
// 	{
// 		if (ft_strequ(head->name, k))
// 			break ;
// 		head = head->next;
// 	}
// 	if (head)
// 	{
// 		ft_putstr(head->name);
// 		write(1, "=", 1);
// 		ft_putendl(head->path);
// 	}
// }

=======
>>>>>>> dev
int			ft_hash(void)
{
	//
	return (1);
}*/

#define FLAG_R 0x1
#define FLAG_D 0x2
#define FLAG_L 0x4
#define FLAG_P 0x8
#define FLAG_T 0x10
#define FLAGS "r"

static	void	hash_find_flags(int *flags, char c)
{
	if (c == 'r')
		*flags |= FLAG_R;
	else
	{
		hash_invalid_option(c);
		hash_usage();
	}
}

static	int		hash_flags_check(char **argv, int *i)
{
	int		j;
	int		flags;

	flags = 0;
	j = 0;
	while (*argv && **argv == '-')
	{
		if (*(*argv + 1) == '-')
		{
			++i;
			return (flags);
		}
		j = 0;
		while (*((*argv) + j))
		{
			hash_find_flags(&flags, *((*argv) + j));
			++j;
		}
		++i;
		++argv;
	}
	return (flags);
}

int				ft_hash(char **argv)
{
	int		flags;
	int		i;

	flags = 0;
	i = 0;
	flags = hash_flags_check(argv, &i);
		return (hash_start_work(flags, (argv + i)));
}
