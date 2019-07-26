/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_print_error.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwisoky <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/01 13:19:46 by dwisoky           #+#    #+#             */
/*   Updated: 2019/07/26 20:59:54 by dwisoky          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void		*parser_print_error(char *error)
{
	g_error_pars = 1;
	ft_putstr_fd("21sh: syntax error near unexpected token `", 2);
	ft_putstr_fd(error, 2);
	ft_putendl_fd("'", 2);
	return (NULL);
}
