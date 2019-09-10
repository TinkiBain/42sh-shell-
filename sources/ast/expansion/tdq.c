/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tdq.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggwin-go <ggwin-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/14 16:13:52 by jterry            #+#    #+#             */
/*   Updated: 2019/08/27 15:23:57 by ggwin-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

static void		spec_char_hendler(int *i, char *str, int *i_t, char **tmp)
{
	(*i) += 1;
	if (str[*i] == 'n')
		(*tmp)[*i_t] = '\n';
	else if (str[*i] == 't')
		(*tmp)[*i_t] = '\t';
	else if (str[*i] == 'v')
		(*tmp)[*i_t] = '\v';
	else if (str[*i] == 'f')
		(*tmp)[*i_t] = '\f';
	else if (str[*i] == 'b')
		(*tmp)[*i_t] = '\b';
	else if (str[*i] == 'a')
		(*tmp)[*i_t] = '\a';
	else if (str[*i] == 'r')
		(*tmp)[*i_t] = '\r';
	else if (!check_spec_symboli_dq(str[*i]))
		(*tmp)[*i_t] = str[*i];
	else
	{
		(*tmp)[(*i_t)++] = '\\';
		(*tmp)[*i_t] = str[*i];
	}
	*i_t += 1;
}

int				cleaner_while(char **tmp, int *t_i, int *i, char *str)
{
	if (str[*i] == '\\')
		(*i) += 1;
	else if (str[*i] == '\'')
	{
		while (str[++(*i)] != '\'')
			(*tmp)[(*t_i)++] = str[*i];
		return (-1);
	}
	else if (str[*i] == '\"')
	{
		while (str[++(*i)] != '\"')
		{
			if (str[*i] == '\\')
				spec_char_hendler(i, str, t_i, tmp);
			else
				(*tmp)[(*t_i)++] = str[*i];
		}
		return (-1);
	}
	return (1);
}

static char		*cleaner(char *str)
{
	char	*tmp;
	int		i;
	int		t_i;

	i = -1;
	t_i = 0;
	tmp = ft_strnew(ft_strlen(str));
	while (str[++i])
	{
		if (cleaner_while(&tmp, &t_i, &i, str) < 0)
			continue ;
		tmp[t_i++] = str[i];
	}
	free(str);
	str = ft_xstrdup(tmp);
	free(tmp);
	return (str);
}

void			tdq_while(int *i, char **str)
{
	if ((*str)[*i] == '\\')
		(*i) += 1;
	else if ((*str)[*i] == '\'')
		while ((*str)[++(*i)])
		{
			if ((*str)[*i] == '\'')
				break ;
		}
	else if ((*str)[*i] == '\"')
	{
		(*i) += 1;
		while ((*str)[*i] && (*str)[*i] != '\"')
		{
			if ((*str)[*i] == '$' && (*str)[(*i) + 1]
					&& check_spec_symbol((*str)[(*i) + 1]))
				dollar(i, str);
			else if ((*str)[*i] == '\\')
				(*i) += 1;
			(*i) += 1;
		}
	}
	else if ((*str)[*i] == '$' && (*str)[(*i) + 1]
			&& check_spec_symbol((*str)[(*i) + 1]))
		dollar(i, str);
}

char			*tdq(char *str)
{
	char	*tmp;
	int		i;

	i = 0;
	tmp = str;
	while (str[i] != '\0')
	{
		tdq_while(&i, &str);
		i++;
	}
	if (*str == '~')
	{
		str = cleaner(str);
		if ((tmp = tilda_check(str)) != NULL)
			str = tmp;
	}
	else
		str = cleaner(str);
	return (str);
}
