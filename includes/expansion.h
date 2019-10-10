/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansion.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwisoky <dwisoky@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 15:01:53 by ggwin-go          #+#    #+#             */
/*   Updated: 2019/10/10 16:43:22 by dwisoky          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXPANSION_H
# define EXPANSION_H

void	dollar(int *j, char **str);
char	*tilda_check(char *str);
char	*tdq(char *str);
char	*ft_dollar_word(char *str, int k, int *j);
char	*brace_handler(char *str, int *j);
char	*buf_finder(char *tmp);
int		back_bigest_eq(char *s1, char *s2);
int		forward_smaller_eq(char *s1, char *s2);
int		forward_bigest_eq(char *s1, char *s2);
char	*substitution(char *str);
char	*tdq_substitution(char *str);
char	*cleaner(char *str);

int		check_spec_symbol(char c);
int		check_spec_symboli_dq(char c);
int		back_smaller_eq(char *s1, char *s2);

#endif
