/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dollar_brace.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jterry <jterry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/22 18:00:07 by jterry            #+#    #+#             */
/*   Updated: 2019/10/07 16:51:14 by jterry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

static char			*freed_proc_value(char *bud, char *value, int len, int flag)
{
	free(value);
	if (flag == 1)
		return(ft_strdup(bud));
	else
		return(ft_strndup(bud, len));
}

static char 		*value_rep(char *value)
{
	int i;

	i = 0;
	value = ft_strdup(value);
	while (value[i] != '}')
		i++;
	value[i] = '\0';
	value = tdq(value);
	return (value);
}

static char			*back_deleter(char *bud, char *value, int flag)
{
	int len;

	len = 0;

	value = value_rep(value);
	if (*value == '\0')
		return (ft_strdup(bud));
	if (flag == 0)
	{
		if ((len = back_smaller_eq(bud, value)) < 0)
			return (freed_proc_value(bud, value, 0, 1));
		return(freed_proc_value(bud, value, len, 0));
	}
	else
	{
		if ((len = back_bigest_eq(bud, value)) < 0)
			return (freed_proc_value(bud, value, 0, 1));
		return(freed_proc_value(bud, value, len, 0));
	}
}

static char			*forward_deleter(char *bud, char *value, int flag)
{
	int len;
	char *tmp;
	int i;

	i = 0;
	len = 0;
	value = value_rep(value);
	if (*value == '\0')
		return (ft_strdup(bud));
	if (flag == 0)
	{
		if ((len = forward_smaller_eq(bud, value)) < 0)
			return (freed_proc_value(bud, value, 0, 1));
		tmp = malloc(sizeof(char) * (ft_strlen(bud) - len + 1));
		while (bud[len])
		{
			tmp[i] = bud[len];
			i++;
			len++;
		}
		tmp[i] = '\0';
		//free(bud);
		return(freed_proc_value(tmp, value, len, 0));
	}
	else
	{
		if ((len = forward_bigest_eq(bud, value)) < 0)
			return (freed_proc_value(bud, value, 0, 1));
		tmp = malloc(sizeof(char) * (ft_strlen(bud) - len + 1));
		while (bud[len])
		{
			tmp[i] = bud[len];
			i++;
			len++;
		}
		tmp[i] = '\0';
		//free(bud);
		return(freed_proc_value(tmp, value, len, 0));
	}
	return(bud);
}

static char			*brace_handler_plus(char *buf, char *str)
{
	int i;

	i = 1;
	printf ("-%s %s-\n", buf, str);
	if (*str == '%' && *(str + 1) == '%')
		return (back_deleter(buf, str + 2, 1));
	else if (*str == '%')
		return (back_deleter(buf, str + 1, 0));
	else if (*str == '#' && *(str + 1) == '#')
		return (forward_deleter(buf, str + 2, 1));
	else if (*str == '#')
		return (forward_deleter(buf, str + 1, 0));

	return(ft_strdup(buf));
}

char				*brace_handler(char *str, int *j)
{
	int		len;
	int		i;
	char	*tmp;
	char	*bud_bear;

	i = 0;
	len = -1;
	while (str[i] && str[i] != '}')
		i++;
	//printf ("%d %d %c\n", i, *j, str[*j]);
	*j += i + 2;
	tmp = (char *)ft_xmalloc(sizeof(char) * (i + 1));
	while (++len < i && check_spec_symbol(str[len]))
		tmp[len] = str[len];
	tmp[len] = '\0';
	bud_bear = buf_finder(tmp);
	if (str[len] != '}')
		return(brace_handler_plus(bud_bear, &str[len]));
	return (ft_strdup(bud_bear));
}
