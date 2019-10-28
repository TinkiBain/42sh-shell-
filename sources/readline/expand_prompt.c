/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_prompt.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelisan <gmelisan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 19:33:41 by gmelisan          #+#    #+#             */
/*   Updated: 2019/10/28 19:17:49 by gmelisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "expand_prompt.h"
#include "colors.h"

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

static char		*getcwd_tilde(char *s)
{
	t_string	path;
	char		*home;
	char		*loc;
	size_t		i;

	path.s = s;
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

static char		*getcwd_expand(void)
{
	struct stat		st_cwd;
	struct stat		st_pwd;
	char			*cwd;
	char			*pwd;

	cwd = getcwd(NULL, 0);
	pwd = ft_xstrdup(get_var_value("PWD"));
	ft_bzero(&st_cwd, sizeof(st_cwd));
	ft_bzero(&st_pwd, sizeof(st_pwd));
	if (stat(cwd, &st_cwd) < 0)
		loginfo("stat returned -1 (%s)", cwd);
	else if (stat(pwd, &st_pwd) < 0)
		loginfo("stat returned -1 (%s)", pwd);
	if (st_cwd.st_ino == st_pwd.st_ino)
	{
		free(cwd);
		return (getcwd_tilde(pwd));
	}
	else
	{
		free(pwd);
		return (getcwd_tilde(cwd));
	}
}

void			expand_prompt(t_string *str)
{
	extern char	*g_project_name;
	char		*p;

	convert_escapes(str);
	str_xreplace(str, "%s", g_project_name);
	str_xreplace(str, "%v", VERSION);
	str_xreplace(str, "%u", getlogin());
	str_xreplace(str, "%w", (p = getcwd_expand()));
	str_xreplace(str, "%black", COLOR_BLACK);
	str_xreplace(str, "%red", COLOR_RED);
	str_xreplace(str, "%green", COLOR_GREEN);
	str_xreplace(str, "%yellow", COLOR_YELLOW);
	str_xreplace(str, "%blue", COLOR_BLUE);
	str_xreplace(str, "%purple", COLOR_PURPLE);
	str_xreplace(str, "%cyan", COLOR_CYAN);
	str_xreplace(str, "%white", COLOR_WHITE);
	str_xreplace(str, "%grey", COLOR_GREY);
	str_xreplace(str, "%eoc", COLOR_EOC);
	free(p);
}
