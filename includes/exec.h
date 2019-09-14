/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggwin-go <ggwin-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/03 20:40:22 by dwisoky           #+#    #+#             */
/*   Updated: 2019/09/14 16:18:59 by gmelisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXEC_H
# define EXEC_H

# include "jobs.h"
# include "parser.h"
# include "lexer.h"

int			call_exec(const char **av, char ***env);
int			change_dir_with_flag(const char *dir);
int			change_dir_without_flag(const char *dir);
int			cd_error(const char *dir);
int			alias(const char **av);
int			unalias(const char **av);
int			alias_free_all();
void		*cd_error_invalid_flag(char c);

#endif
