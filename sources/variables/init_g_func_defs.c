/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_g_func_defs.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggwin-go <ggwin-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 23:37:05 by ggwin-go          #+#    #+#             */
/*   Updated: 2019/10/14 01:12:08 by ggwin-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

extern t_dict		*g_func_defs;
extern char			**g_var;

/*
**	Function definition example:	"BASH_FUNC_def%%=() {  ( ls )
**									}"
**	Prefix string (before functions definition name) = "BASH_FUNC_"
*/

#define PREFIX_LEN	10
#define PREFIX_STR	"BASH_FUNC_"

static void			add_g_func_def(char *var)
{
	extern char		**environ;
	char			*p;
	char			*name;
	char			*body;
	t_dict			*func;

	p = NULL;
	if (!var || !(p = ft_strstr(var, "%%=()")))
		return ;
	name = ft_xstrndup(var + PREFIX_LEN, p - var - PREFIX_LEN);
	body = ft_xstrdup(ft_strstr(p, ")") + 1);
	func = ft_init_dict(name, body);
	ft_dict_push_back(&g_func_defs, func);
	ft_strdel(&name);
	ft_strdel(&body);
}

void				init_g_func_defs(void)
{
	extern char		**environ;
	char			**tmp;
	size_t			len;

	g_func_defs = NULL;
	if (!environ)
		return ;
	tmp = environ;
	while (*tmp)
	{
		len = ft_strlen(PREFIX_STR);
		if (ft_strnequ(*tmp, PREFIX_STR, PREFIX_LEN))
			add_g_func_def(*tmp);
		++tmp;
	}
}
