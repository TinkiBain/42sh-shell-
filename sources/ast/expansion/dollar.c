/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dollar.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jterry <jterry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 21:39:09 by jterry            #+#    #+#             */
/*   Updated: 2019/09/22 21:23:12 by jterry           ###   ########.fr       */
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
	(*str) = ft_strrejoin((*str), tmp, 3);
	(*j) = l - 1;
}

static void		modular_conversion(char *word, char **str, int l, int *j)
{
	char	*residue;

	residue = ft_xstrdup(&(*str)[*j + 1]);

	printf ("w - %s \nr - %s\n", word, residue);
	(*str)[l] = '\0';
	if (word)
		(*str) = ft_strrejoin((*str), word, 1);
	if (residue)
		(*str) = ft_strrejoin((*str), residue, 3);
	*j = l + ft_strlen(word) - 1;
	if (word)
		free(word);
}

void			dollar(int *j, char **str)
{
	char	*word;
	int		l;

	l = *j;
	if (!(word = ft_dollar_word(&(*str)[(*j) + 1], -1, j)))
	{
		word_not_found(str, j, l);
		return ;
	}

	if ((*str)[(*j) + 1] == '$')
		(*j) += 1;
	else
		while ((*str)[*j + 1] && check_spec_symbol((*str)[*j + 1])
				&& (*str)[*j + 1] != '$' && (*str)[*j] != '}')
			(*j) += 1;
	printf ("%d\n", *j);
	modular_conversion(word, str, l, j);
}
