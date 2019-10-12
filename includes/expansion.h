/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansion.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jterry <jterry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 15:01:53 by ggwin-go          #+#    #+#             */
/*   Updated: 2019/10/12 20:56:36 by dwisoky          ###   ########.fr       */
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
char	*value_rep(char *value);
char	*freed_proc_value(char *bud, char *value, int len, int flag);
char	*double_dote(char *str, char *value, char *buf, char *name);

char	*substitution(char *str);
char	*cleaner(char *str);

int		check_spec_symbol(char c);
int		check_spec_symboli_dq(char c);

char	*forward_deleter(char *bud, char *value, int flag);
int		forward_smaller_eq(char *s1, char *s2);
int		forward_bigest_eq(char *s1, char *s2);

int		back_bigest_eq(char *s1, char *s2);
int		back_smaller_eq(char *s1, char *s2);

#endif
