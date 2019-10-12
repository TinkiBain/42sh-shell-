/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dollar_brace.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jterry <jterry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/22 18:00:07 by jterry            #+#    #+#             */
/*   Updated: 2019/10/12 20:47:53 by dwisoky          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

char			*freed_proc_value(char *bud, char *value, int len, int flag)
{
	free(value);
	if (flag == 1)
		return (ft_xstrdup(bud));
	else
		return (ft_xstrndup(bud, len));
}

char			*value_rep(char *value)
{
	int i;

	i = 0;
	value = ft_xstrdup(value);
	while (value[i] != '}')
		i++;
	if (i == 0)
		return (NULL);
	value[i + 1] = '\0';
	value = tdq(value);
	return (value);
}

static char		*back_deleter(char *bud, char *value, int flag)
{
	int len;

	len = 0;
	value = value_rep(value);
	if (*value == '\0')
		return (ft_xstrdup(bud));
	if (flag == 0)
	{
		if ((len = back_smaller_eq(bud, value)) < 0)
			return (freed_proc_value(bud, value, 0, 1));
		return (freed_proc_value(bud, value, len, 0));
	}
	else
	{
		if ((len = back_bigest_eq(bud, value)) < 0)
			return (freed_proc_value(bud, value, 0, 1));
		return (freed_proc_value(bud, value, len, 0));
	}
}

static char		*brace_handler_plus(char *buf, char *str, char *name)
{
	int		i;
	char	*value;
	char	site_name[2048];

	i = -1;
	while (name[++i])
		site_name[i] = name[i];
	free(name);
	i = 1;
	value = NULL;
	if (*str == '%' && *(str + 1) == '%')
		return (back_deleter(buf, str + 2, 1));
	else if (*str == '%')
		return (back_deleter(buf, str + 1, 0));
	else if (*str == '#' && *(str + 1) == '#')
		return (forward_deleter(buf, str + 2, 1));
	else if (*str == '#')
		return (forward_deleter(buf, str + 1, 0));
	else if (*str == ':')
		return (double_dote(str, value, buf, ft_strdup(site_name)));
	return (ft_xstrdup(buf));
}

char			*brace_handler(char *str, int *j)
{
	int		len;
	int		i;
	char	*tmp;
	char	*bud_bear;
	int		count;

	count = 0;
	i = 0;
	len = -1;
	while (str[i] && str[i] != '}')
	{
		if (str[i] == '{')
			count++;
		i++;
	}
	*j += i + 2 + count;
	tmp = (char *)ft_xmalloc(sizeof(char) * (i + 1));
	while (++len < i && check_spec_symbol(str[len]))
		tmp[len] = str[len];
	tmp[len] = '\0';
	bud_bear = buf_finder(tmp);
	if (str[len] != '}')
		return (brace_handler_plus(bud_bear, &str[len], tmp));
	free(tmp);
	return (ft_xstrdup(bud_bear));
}
