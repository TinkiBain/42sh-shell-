/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dollar_brace_forward.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jterry <jterry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 17:44:02 by jterry            #+#    #+#             */
/*   Updated: 2019/10/14 18:57:52 by jterry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

static char		*forward_bigest(int len, char *value, char *bud)
{
	char	*tmp;
	int		i;

	i = 0;
	tmp = NULL;
	if ((len = forward_smaller_eq(bud, value)) < 0)
		return (freed_proc_value(bud, value, 0, 1));
	tmp = ft_xmalloc(sizeof(char) * (ft_strlen(bud) - len + 1));
	while (bud[len])
	{
		tmp[i] = bud[len];
		i++;
		len++;
	}
	tmp[i] = '\0';
	return (freed_proc_value(tmp, value, len, 0));
}

static char		*forward_smaller(int len, char *value, char *bud)
{
	char	*tmp;
	int		i;

	i = 0;
	tmp = NULL;
	if ((len = forward_bigest_eq(bud, value)) < 0)
		return (freed_proc_value(bud, value, 0, 1));
	tmp = ft_xmalloc(sizeof(char) * (ft_strlen(bud) - len + 1));
	while (bud[len])
	{
		tmp[i] = bud[len];
		i++;
		len++;
	}
	tmp[i] = '\0';
	return (freed_proc_value(tmp, value, len, 0));
}

char			*forward_deleter(char *bud, char *value, int flag)
{
	int		len;
	int		i;

	i = 0;
	len = 0;
	value = value_rep(value);
	if (!value)
		return (ft_xstrdup(bud));
	if (*value == '\0')
		return (ft_xstrdup(bud));
	if (flag == 0)
		return (forward_bigest(len, value, bud));
	else
		return (forward_smaller(len, value, bud));
	return (bud);
}
