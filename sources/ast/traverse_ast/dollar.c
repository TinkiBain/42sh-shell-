/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dollar.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggwin-go <ggwin-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 21:39:09 by jterry            #+#    #+#             */
/*   Updated: 2019/08/23 18:15:52 by jterry           ###   ########.fr       */
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
	while (str[i] && check_spec_symbol(str[i]) && str[i] != '$')
		i++;
	tmp = (char *)ft_xmalloc(sizeof(char) * (i + 1));
	while (++k < i)
		tmp[k] = str[k];
	tmp[k] = '\0';
	if ((buf = get_value_from_all_vars(tmp)) == NULL)
	{
		free(tmp);
		return (0);
	}
	free(tmp);
	return (buf);
}

void		dollar(int *j, char **str)
{
	char	*tmp;
	char	*kek;
	int		l;
	int		flag;

	flag = 0;
	l = *j;
	if (!(tmp = ft_dollar_word(&(*str)[(*j) + 1], -1)))
	{
		while ((*str)[*j + 1] && check_spec_symbol((*str)[*j + 1]) && (*str)[*j + 1] != '$')
				(*j) += 1;
		tmp = ft_xstrdup(&(*str)[*j + 1]);
		(*str)[l] = '\0';
		(*str) = ft_strrejoin((*str), tmp, 3);
		(*j) = l - 1;
		return ;
	}
	if ((*str)[(*j) + 1] == '$')
		(*j) += 1;
	else
		while ((*str)[*j + 1] && check_spec_symbol((*str)[*j + 1]) && (*str)[*j + 1] != '$')
			(*j) += 1;
	kek = ft_xstrdup(&(*str)[*j + 1]);
	(*str)[l] = '\0';
	if ((*str)[l + 1] == '$')
		flag = 1;;
	if (tmp)
		(*str) = ft_strrejoin((*str), tmp, 1);
	if (kek)
		(*str) = ft_strrejoin((*str), kek, 3);
	*j = l + ft_strlen(tmp) - 1;
	if (flag == 1)
		free(tmp);
}
