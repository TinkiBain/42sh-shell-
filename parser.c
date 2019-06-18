/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwisoky <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/13 20:31:16 by dwisoky           #+#    #+#             */
/*   Updated: 2019/06/13 21:00:35 by dwisoky          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int			parser(char *cmd, t_exec *exec)
{
	i = parser_check_cmd(cmd);
	while (cmd)
	{
		
	}
	return (1);
}

int		main(void)
{
	char buf[1024];
	char *str;
	t_exec	*cmd;

	while (1)
	{
		buf[read(0, &buf, 1023) - 1] = '\0';
		if (ft_strequ(buf, "exit"))
			break ;
		str = ft_strdup(buf);
		parser(str, &cmd);
		free(str);
	}
	return (0);
}
