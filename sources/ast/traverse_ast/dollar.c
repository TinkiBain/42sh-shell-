/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dollar.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggwin-go <ggwin-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 21:39:09 by jterry            #+#    #+#             */
/*   Updated: 2019/08/31 14:19:00 by ggwin-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

static char		*ft_dollar_word(char *str, int k)
{
	char	*tmp;
	int		i;
	char	*buf;
	int		flag;

	i = 0;
	flag = 0;
	if (str[i] && str[i] == '$')
		return (ft_itoa(getpid()));
	if (str[i] == '{' && (flag = 1))
		while (str[i + 1] && str[i + 1] != '}')
			i++;
	else
		while (str[i] && check_spec_symbol(str[i]) && str[i] != '$')
			i++;
	tmp = (char *)ft_xmalloc(sizeof(char) * (i + 1));
	while (++k < i)
		tmp[k] = str[k + flag];
	tmp[k] = '\0';
	buf = get_value_from_all_vars(tmp);
	free(tmp);
	if ((buf) == NULL)
		return (0);
	return (buf);
}

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

void			modular_conversion(char *word, char **str, int l, int *j)
{
	char	*residue;
	int		flag;

	residue = ft_xstrdup(&(*str)[*j + 1]);
	(*str)[l] = '\0';
	flag = (*str)[l + 1] == '$' ? 1 : 0;
	if (word)
		(*str) = ft_strrejoin((*str), word, 1);
	if (residue)
		(*str) = ft_strrejoin((*str), residue, 3);
	*j = l + ft_strlen(word) - 1;
	if (flag == 1)
		free(word);
}

void			dollar(int *j, char **str)
{
	char	*word;
	int		l;

	l = *j;
	if (!(word = ft_dollar_word(&(*str)[(*j) + 1], -1)))
	{
		word_not_found(str, j, l);
		return ;
	}
	if ((*str)[(*j) + 1] == '$')
		(*j) += 1;
	else
		while ((*str)[*j + 1] && check_spec_symbol((*str)[*j + 1])
				&& (*str)[*j + 1] != '$')
			(*j) += 1;
	modular_conversion(word, str, l, j);
}
