/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_var_shellopts.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggwin-go <ggwin-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/28 15:56:18 by ggwin-go          #+#    #+#             */
/*   Updated: 2019/09/01 16:33:47 by ggwin-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

void	set_var_shellopts(void)
{
	extern t_opt	g_opt;
	extern char		**g_var;
	char			*shellopts;
	int				flag;

	flag = 0;
	shellopts = ft_strdup("SHELLOPTS=");
	if (g_opt.vi_mode)
		shellopts = ft_strrejoin(shellopts, (!flag++) ? "vi" : ":vi", 1);
	if (g_opt.emacs_mode)
		shellopts = ft_strrejoin(shellopts, (!flag++) ? "emacs" : ":emacs", 1);
	if (g_opt.enable_color)
		shellopts = ft_strrejoin(shellopts, (!flag++) ? "color" : ":color", 1);
	if (g_opt.noclobber)
		shellopts = ft_strrejoin(shellopts, (!flag++) ? "noclobber"
													: ":noclobber", 1);
	set_var(shellopts, &g_var, 1);
	ft_memdel((void **)&shellopts);
}
