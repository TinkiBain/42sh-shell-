/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansion.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jterry <jterry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 15:01:53 by ggwin-go          #+#    #+#             */
/*   Updated: 2019/09/25 20:50:15 by jterry           ###   ########.fr       */
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

int		check_spec_symbol(char c);
int		check_spec_symboli_dq(char c);
int		back_smaller_eq(char *s1, char *s2);

#endif
