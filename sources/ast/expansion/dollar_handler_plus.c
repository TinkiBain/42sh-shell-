/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dollar_handler_plus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jterry <jterry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/22 17:58:57 by jterry            #+#    #+#             */
/*   Updated: 2019/10/25 16:39:54 by jterry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"
#include "arithmetic.h"

extern t_opt	g_opt;

char			*buf_finder(char *tmp)
{
	char		*buf;

	if ((buf = get_var_value(tmp)) == NULL)
		return (0);
	return (buf);
}

static char		*hash(char *str, int *j)
{
	int			i;
	int			len;
	char		*tmp;
	char		*bud_bear;

	i = 0;
	len = -1;
	while (str[i] && str[i] != '}')
		i++;
	*j += i + 2;
	tmp = (char *)ft_xmemalloc(sizeof(char) * (i + 1));
	while (++len < i && check_spec_symbol(str[len]))
		tmp[len] = str[len];
	tmp[len] = '\0';
	bud_bear = buf_finder(tmp);
	if (!bud_bear)
		return (ft_xstrdup("0"));
	return (ft_itoa(ft_strlen(bud_bear)));
}

static char		*in_brace(char *str, int *j)
{
	if (str[1] && str[1] == '$')
		return (ft_itoa(getpid()));
	else if (str[1] && str[1] == '?')
		return (ft_itoa(g_res_exec));
	else if (str[1] && str[1] == '#')
		return (hash(str + 2, j));
	else
		return (brace_handler(str + 1, j));
}

static char		*next_char_check(char *str, int *j, t_pjobs **local)
{
	char		*tmp;

	tmp = NULL;
	if (*str && *str == '$')
		return (ft_itoa(getpid()));
	else if (*str && *str == '{')
		return (in_brace(str, j));
	else if (*str && *str == '?')
		return (ft_itoa(g_res_exec));
	else if (*str && *str == '(' && str[1] == '(')
	{
		tmp = ft_xstrjoin("$", str);
		tmp[ft_strlen(str) - ft_strlen(parser_find_dollar(tmp)) + 2] = '\0';
		return (arithmetic_exp(tmp));
	}
	else if (*str && *str == '(')
	{
		tmp = ft_xstrjoin("$", str);
		return (substitution(tmp, local));
	}
	else
		return (NULL);
}

char			*ft_dollar_word(char *str, int k, int *j, t_pjobs **local)
{
	char		*tmp;
	char		*src;
	int			i;
	int			flag;

	i = 0;
	flag = 0;
	if ((tmp = next_char_check(str, j, local)))
		return (tmp);
	else if (g_opt.arithmetic_error)
		return (NULL);
	else
		while (str[i] && check_spec_symbol(str[i]) && str[i] != '$')
			i++;
	tmp = (char *)ft_xmemalloc(sizeof(char) * (i + 1));
	while (++k < i)
		tmp[k] = str[k + flag];
	tmp[k] = '\0';
	src = ft_xstrdup(buf_finder(tmp));
	free(tmp);
	return (src);
}
