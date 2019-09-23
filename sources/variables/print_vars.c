/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_vars.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggwin-go <ggwin-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/18 17:28:52 by ggwin-go          #+#    #+#             */
/*   Updated: 2019/09/23 13:47:23 by ggwin-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

static void	print_one_var(char *name, char *value)
{
	write(1, name, value - name - 1);
	ft_putstr("='");
	ft_putstr(value);
	ft_putendl("'");
}

void		print_vars(int show_shell_vars)
{
	extern char		**environ;
	extern char		**g_var;
	char			**tmp;
	char			*p;

	tmp = (show_shell_vars) ? g_var : environ;
	while (*tmp)
	{
		if ((p = ft_strchr(*tmp, '=')))
			print_one_var(*tmp, p + 1);
		++tmp;
	}
}
