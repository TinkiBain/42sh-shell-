/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_prompt.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelisan <gmelisan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 19:33:41 by gmelisan          #+#    #+#             */
/*   Updated: 2019/10/23 23:02:25 by gmelisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "expand_prompt.h"

static void		convert_escapes(t_string *str)
{
	int		i;
	char	c;
	t_uchar	n;
	int		count;

	i = -1;
	n = 0;
	while ((c = str_get(*str, ++i)))
	{
		if (c == '\\')
			n = ft_atoi_octal(&str->s[i + 1], &count);
		if (n)
		{
			str_remove(str, i, count + 1);
			str_xinsert(str, i, (char *)&n, 1);
		}
		n = 0;
	}
}

static char		*getcwd_tilde(void)
{
	t_string	path;
	char		*home;
	char		*loc;
	size_t		i;

	path.s = getcwd(NULL, 0);
	str_fixlen(&path);
	home = get_var_value("HOME");
	if (!home)
		return (path.s);
	loc = ft_strstr(path.s, home);
	if (!loc)
		return (path.s);
	i = -1;
	while (++i < path.len)
		if (path.s + i == loc)
			break ;
	if (i == path.len)
		return (path.s);
	str_remove(&path, i, ft_strlen(home));
	str_xinsert(&path, i, "~", 1);
	return (path.s);
}

void			expand_prompt(t_string *str)
{
	extern char	*g_project_name;
	char		*p;

	convert_escapes(str);
	str_xreplace(str, "%s", g_project_name);
	str_xreplace(str, "%v", VERSION);
	str_xreplace(str, "%w", (p = getcwd_tilde()));
	free(p);
}
