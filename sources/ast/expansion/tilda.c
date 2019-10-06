/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tilda.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggwin-go <ggwin-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/27 18:08:41 by jterry            #+#    #+#             */
/*   Updated: 2019/09/23 14:20:31 by ggwin-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

static char			*user_founder(char *str)
{
	char			*tmp;
	struct passwd	*pas;

	tmp = ft_xstrdup(&str[1]);
	pas = getpwnam(tmp);
	if (!pas)
	{
		free(tmp);
		return (NULL);
	}
	free(tmp);
	tmp = ft_xstrdup(pas->pw_dir);
	return (tmp);
}

static char			*tilda(char *str, char *buf)
{
	if (str[1] == '+' && (str[2] == '/' || !str[2]))
	{
		if ((buf = get_var_value("PWD")) < 0)
			return (str);
		buf = ft_strrejoin(buf, &str[2], 0);
	}
	else if (str[1] == '-' && (str[2] == '/' || !str[2]))
	{
		if ((buf = get_var_value("OLDPWD")) < 0)
			return (str);
		buf = ft_strrejoin(buf, &str[2], 0);
	}
	else if (str[1] == '/')
	{
		buf = get_var_value("HOME");
		buf = ft_strrejoin(buf, &str[1], 0);
		return (buf);
	}
	else if (str[1])
		return (user_founder(str));
	else
		buf = get_var_value("HOME");
	return (ft_xstrdup(buf));
}

char				*tilda_check(char *str)
{
	char			*tmp;

	if (*str == '~')
	{
		if (!(tmp = tilda(str, NULL)))
		{
			free(tmp);
			return (NULL);
		}
		free(str);
		return (tmp);
	}
	return (NULL);
}
