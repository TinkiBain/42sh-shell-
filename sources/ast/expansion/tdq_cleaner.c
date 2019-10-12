/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tdq_cleaner.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jterry <jterry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 19:16:10 by jterry            #+#    #+#             */
/*   Updated: 2019/10/12 19:19:44 by jterry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

static void		spec_char_handler(int *i, char *str, int *i_t, char **tmp)
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

static void		cleaner_escape(char *str, int *i)
{
	if (str[*i + 1] == '\n')
		(*i) += 2;
	else
		++(*i);
}

static int		cleaner_while(char **tmp, int *t_i, int *i, char *str)
{
	if (str[*i] == '\\')
		cleaner_escape(str, i);
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
				spec_char_handler(i, str, t_i, tmp);
			else
				(*tmp)[(*t_i)++] = str[*i];
		}
		return (-1);
	}
	return (1);
}

char		*cleaner(char *str)
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
