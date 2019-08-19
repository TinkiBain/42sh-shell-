/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_variables.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelisan </var/spool/mail/vladimir>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/15 03:07:14 by gmelisan          #+#    #+#             */
/*   Updated: 2019/08/19 08:57:19 by gmelisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "actions.h"

extern char		**environ;
extern char		**g_var;

static int		match(t_string name, t_string query)
{
	int i;

	i = -1;
	while (str_get(query, ++i))
	{
		if (str_get(name, i) != str_get(query, i))
			return (0);
	}
	return (1);
}

static void		get_env_vars(t_vector *vec, t_string query)
{
	t_string	str;
	char		*s;
	int			i;
	int			j;

	i = -1;
	while ((s = environ[++i]))
	{
		str = str_xcopy(s);
		j = -1;
		while (str_get(str, ++j))
			if (str_get(str, j) == '=')
			{
				str.s[j] = 0;
				str_fixlen(&str);
			}
		if (match(str, query))
			vec_xaddback(vec, &str);
		else
			str_delete(&str);
	}	
}

/* static void		get_shell_vars(t_vector *vec, t_string query) */
/* { */
/* 	t_string	str; */
/* 	char		*s; */
/* 	int			i; */
/* 	int			j; */

/* 	i = -1; */
/* 	while ((s = g_var[++i])) */
/* 	{ */
/* 		str = str_xcopy(s); */
/* 		j = -1; */
/* 		while (str_get(str, ++j)) */
/* 			if (str_get(str, j) == '=') */
/* 			{ */
/* 				str.s[j] = 0; */
/* 				str_fixlen(&str); */
/* 			} */
/* 		if (match(str, query)) */
/* 			vec_xaddback(vec, &str); */
/* 		else */
/* 			str_delete(&str); */
/* 	}	 */
/* } */

t_vector		get_variables_old(t_string query)
{
	t_vector vec;

	vec = vec_xcreate(0, sizeof(t_string));
	get_env_vars(&vec, query);
	/* get_shell_vars(&vec, query); */
	ft_qsort(vec.v, vec.len, vec.size, cmp_pstring);
	return (vec);
}

void			get_variables(t_string query, char ***start, int *n)
{
	extern char	**g_var_names;
	int i;

	if (!start || !n)
		return ;
	*start = NULL;
	*n = 0;
	i = -1;
	while (g_var_names[++i])
	{
		if (ft_strnequ(query.s, g_var_names[i], query.len))
		{
			*start = &g_var_names[i];
			while (g_var_names[i] && ft_strnequ(query.s, g_var_names[i], query.len))
			{
				*n += 1;
				i++;
			}
			return ;
		}
	}
}
