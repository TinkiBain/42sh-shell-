/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dollar.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jterry <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 21:39:09 by jterry            #+#    #+#             */
/*   Updated: 2019/08/12 17:50:12 by jterry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

extern char		**environ;

static int		ft_check(char c)
{
	if (c == '#' || c == '%' || c == '!' || c == '@' || c == '"' || c == 39
			|| c == '^' || c == '*' || c == '(' || c == ')'
			|| c == '=' || c == '/')
		return (0);
	return (1);
}

static char		*ft_dollar_word(char *str, int k)
{
	char	*tmp;
	int		i;
	char	*buf;

	i = 0;
	if (str[i] && str[i] == '$')
		return (ft_itoa(getpid()));
	while (str[i] && ft_check(str[i]))
		i++;
	tmp = malloc(i + 1);
	while (++k < i)
		tmp[k] = str[k];
	tmp[k] = '\0';
	if ((buf = ft_getenv(tmp, environ)) == NULL)
	{
		free(tmp);
		return (0);
	}
	free(tmp);
	tmp = ft_strdup(buf);
	return (tmp);
}

static void		sokrat(int *j, char **str)
{
	char	*tmp;
	char	*kek;
	int		l;

	l = *j;
	if (!(tmp = ft_dollar_word(&(*str)[(*j) + 1], -1)))
	{
		(*str)[l] = '\0';
		return ;
	}
	if ((*str)[(*j) + 1] == '$')
		(*j) += 2;
	else
		while ((*str)[*j] && ft_check((*str)[*j]))
			(*j) += 1;
	kek = ft_strdup(&(*str)[*j]);
	(*str)[l] = '\0';
	if (tmp)
		(*str) = ft_strrejoin((*str), tmp, 3);
	if (kek)
		(*str) = ft_strrejoin((*str), kek, 3);
}

char			*ft_dollar(char *str)
{
	int		i;

	i = -1;
	while (str[++i])
	{
		if (str[i] == '$' && str[i + 1])
			sokrat(&i, &str);
	}
	return (str);
}
