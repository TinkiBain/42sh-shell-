/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dollar.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jterry <jterry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 21:39:09 by jterry            #+#    #+#             */
/*   Updated: 2019/10/13 17:14:12 by wtalea           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

static void		word_not_found(char **str, int *j, int l)
{
	char	*tmp;

	while ((*str)[*j + 1] && check_spec_symbol((*str)[*j + 1])
			&& (*str)[*j + 1] != '$')
		(*j) += 1;
	tmp = ft_xstrdup(&(*str)[*j + 1]);
	(*str)[l] = '\0';
	(*str) = ft_xstrrejoin((*str), tmp, 3);
	(*j) = l - 1;
}

static void		modular_conversion(char *word, char **str, int l, int *j)
{
	char	*residue;

	residue = ft_xstrdup(&(*str)[*j + 1]);
	(*str)[l] = '\0';
	if (word)
		(*str) = ft_xstrrejoin((*str), word, 1);
	if (residue)
		(*str) = ft_xstrrejoin((*str), residue, 3);
	if (word)
	{
		*j = l + ft_strlen(word) - 1;
		free(word);
	}
}

void			dollar(int *j, char **str)
{
	char	*word;
	int		l;
	char	*tmp;

	tmp = NULL;
	l = *j;
	if (!(word = ft_dollar_word(&(*str)[(*j) + 1], -1, j)) && !(str[*j]))
	{
		word_not_found(str, j, l);
		return ;
	}
	if ((*str)[(*j) + 1] == '$')
		(*j) += 1;
	else if ((*str)[*j + 1] == '(' && (*str)[*j + 2] == '(')
		*j += ft_strlen(*str) - ft_strlen(parser_find_dollar(*str));
	else if ((*str)[*j + 1] == '(')
		*j += ft_strlen(*str) - ft_strlen(parser_find_dollar(*str));
	else
		while ((*str)[*j + 1] && check_spec_symbol((*str)[*j + 1])
				&& (*str)[*j + 1] != '$' && (*str)[*j] != '}')
			(*j) += 1;
	modular_conversion(word, str, l, j);
}
