/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_g_var_names.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggwin-go <ggwin-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/17 20:56:19 by ggwin-go          #+#    #+#             */
/*   Updated: 2019/08/19 23:34:06 by ggwin-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"
#include "libft.h"

static size_t	get_array_size(char **arr)
{
	size_t		size;

	size = 0;
	while (*(arr++))
		++size;
	return (size);
}

static int		copy_var_names(char **var_names, char **vars, size_t *i)
{
	char	*p;

	while (*vars)
	{
		if ((p = ft_strchr(*vars, '=')))
		{
			*(var_names + (*i)++) = ft_strndup(*vars, p - *vars);
		}
		++vars;
	}
	return (0);
}

static void		remove_duplicates(char ***vars)
{
	char		**tmp;
	char		**p;

	if (vars)
	{
		tmp = *vars;
		while (*tmp)
		{
			while (*(tmp + 1) && ft_strequ(*tmp, *(tmp + 1)))
			{
				p = tmp;
				free(*p);
				while (*p)
				{
					*p = *(p + 1);
					++p;
				}
			}
			++tmp;
		}
	}
}

int				fill_g_var_names(void)
{
	extern char	**environ;
	extern char	**g_var;
	extern char	**g_var_names;
	char		**tmp;
	size_t		size;

	if (g_var_names)
		ft_free_double_ptr_arr((void ***)&g_var_names);
	size = get_array_size(environ);
	size += get_array_size(g_var);
	g_var_names = (char **)ft_xmalloc(sizeof(char *) * (size + 1));
	ft_bzero(g_var_names, sizeof(char *) * (size + 1));
	tmp = environ;
	size = 0;
	copy_var_names(g_var_names, environ, &size);
	copy_var_names(g_var_names, g_var, &size);
	ft_arr_str_qsort(g_var_names, size);
	remove_duplicates(&g_var_names);
	return (0);
}
