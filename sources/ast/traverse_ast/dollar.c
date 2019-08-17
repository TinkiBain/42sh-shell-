/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dollar.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggwin-go <ggwin-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 21:39:09 by jterry            #+#    #+#             */
/*   Updated: 2019/08/18 00:17:41 by ggwin-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

static char		*ft_dollar_word(char *str, int k)
{
	char	*tmp;
	int		i;
	char	*buf;

	i = 0;
	if (str[i] && str[i] == '$')
		return (ft_itoa(getpid()));
	while (str[i] && check_spec_symbol(str[i]))
		i++;
	tmp = xmalloc(i + 1);
	while (++k < i)
		tmp[k] = str[k];
	tmp[k] = '\0';
	if ((buf = get_value_from_all_vars(tmp)) == NULL)
	{
		free(tmp);
		return (0);
	}
	free(tmp);
	tmp = ft_xstrdup(buf);
	return (tmp);
}

void		dollar(int *j, char **str)
{
	char	*tmp;
	char	*kek;
	int		l;

	l = *j;
	if (!(tmp = ft_dollar_word(&(*str)[(*j) + 1], -1)))
	{
		while ((*str)[*j + 1] && check_spec_symbol((*str)[*j + 1]))
				(*j) += 1;
		tmp = ft_xstrdup(&(*str)[*j + 1]);
		(*str)[l] = '\0';
		(*str) = ft_strrejoin((*str), tmp, 3);
		return ;
	}
	if ((*str)[(*j) + 1] == '$')
		(*j) += 2;
	else
		while ((*str)[*j] && check_spec_symbol((*str)[*j + 1]))
			(*j) += 1;
	kek = ft_xstrdup(&(*str)[*j]);
	(*str)[l] = '\0';
	if (tmp)
		(*str) = ft_strrejoin((*str), tmp, 3);
	if (kek)
		(*str) = ft_strrejoin((*str), kek, 3);
}
