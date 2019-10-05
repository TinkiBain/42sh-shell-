/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansion.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggwin-go <ggwin-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 15:01:53 by ggwin-go          #+#    #+#             */
/*   Updated: 2019/10/05 17:56:24 by dwisoky          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXPANSION_H
# define EXPANSION_H

void	dollar(int *j, char **str);
char	*tilda_check(char *str);
char	*tdq(char *str);
char	*substitution(char *str);

int		check_spec_symbol(char c);
int		check_spec_symboli_dq(char c);

#endif
