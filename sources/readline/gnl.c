/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggwin-go <ggwin-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/01 15:57:28 by gmelisan          #+#    #+#             */
/*   Updated: 2019/09/22 20:50:04 by ggwin-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_readline.h"

extern t_opt	g_opt;
extern t_line	*g_line;

static void		sigh_gnl(int sig)
{
	if (sig == SIGINT)
	{
		ft_putstr_fd("\n", g_opt.rl_out);
		ft_putstr_fd(g_line->prompt.s, g_opt.rl_out);
	}
}

static int		gnl_input_loop(void)
{
	int			ret;
	char		c;

	while ((ret = read(g_opt.rl_in, &c, 1)) > 0)
	{
		if (c == NL || (c == CTRL_D))
			break ;
		if (ret < 0)
		{
			print_error("Read error", NULL);
			str_delete(&g_line->result);
			return (ret);
		}
		if (ret == 0)
		{
			str_delete(&g_line->result);
			return (ret);
		}
		str_xaddback(&g_line->result, &c, 1);
	}
	if (g_line->result.len > 0)
		ret = 1;
	return (ret);
}

char			*gnl(char *prompt)
{
	int			ret;
	extern int	g_eof;

	signal(SIGINT, sigh_gnl);
	g_line->result = str_xcreate(0);
	g_line->prompt = str_xcopy(prompt ? prompt : "");
	convert_escapes(&g_line->prompt);
	ft_putstr_fd(g_line->prompt.s, g_opt.rl_out);
	ret = gnl_input_loop();
	if (ret == 0)
		g_eof = 1;
	if (ret <= 0)
		str_delete(&g_line->result);
	if (ret < 0)
		print_error("Read error", NULL);
	str_delete(&g_line->prompt);
	return (g_line->result.s);
}
