/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggwin-go <ggwin-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/03 20:40:22 by dwisoky           #+#    #+#             */
/*   Updated: 2019/09/20 17:58:19 by dwisoky          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXEC_H
# define EXEC_H

# include "jobs.h"
# include "parser.h"
# include "lexer.h"

int			call_exec(const char **av, char ***env);
int			ft_alias(const char **av);
int			ft_unalias(const char **av);
int			alias_free_all();
void		*cd_error_invalid_flag(char c);

#endif
