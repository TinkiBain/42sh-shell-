/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwisoky <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/26 17:14:07 by dwisoky           #+#    #+#             */
/*   Updated: 2019/06/26 17:20:54 by dwisoky          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void	parser(char *str, t_exec **exec)
{
	
}

int		main(void)
{
	char buf[1024];
	t_exec	*exec;

	exec = NULL;
	while (1)
	{
		buf[read(0, &buf, 1023) - 1] = '\0';
		if (ft_strequ("exit", buf))
			break ;
		parser(buf, &exec);
	}
}
