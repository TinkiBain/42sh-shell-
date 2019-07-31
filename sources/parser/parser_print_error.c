/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_print_error.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggwin-go <ggwin-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/01 13:19:46 by dwisoky           #+#    #+#             */
/*   Updated: 2019/07/30 14:22:12 by ggwin-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"
#include "parser.h"

void		*parser_print_error(char *error)
{
	g_error_pars = 1;
	ft_putstr_fd(PROJECT_NAME, 2);
	ft_putstr_fd(": syntax error near unexpected token `", 2);
	ft_putstr_fd(error, 2);
	ft_putendl_fd("'", 2);
	return (NULL);
}
