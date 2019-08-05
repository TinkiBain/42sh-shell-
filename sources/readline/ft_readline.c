/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_readline.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggwin-go <ggwin-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/03 16:29:42 by gmelisan          #+#    #+#             */
/*   Updated: 2019/08/04 21:10:35 by ggwin-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_readline.h"

t_line *g_line;
int		g_logfd;

static void	sig_init(void)
{
	signal(SIGINT, sigh_sigint);
	signal(SIGSEGV, sigh_sigsegv);
	signal(SIGABRT, sigh_sigabrt);
	signal(SIGWINCH, sigh_sigwinch);
	signal(SIGTERM, sigh_sigterm);
	/* signal(SIGTSTP, sigh_ignore); */
}

static void init_line(t_line *line, char *prompt, char *oldline)
{
	t_string temp_str;

	ft_bzero(line, sizeof(t_line));
	line->history_orig = g_history;
	line->history = history_copy(g_history);
	temp_str = str_xcreate(0);
	history_push(line->history, temp_str);
	line->str = (t_string *)line->history->item->content;
	g_line = line;
	line->prompt = str_xcopy(prompt);
	line->vi_mode = g_options.vi_mode;
	line->oldstr = str_xcopy(oldline);
	line->arg = 1;
}

static void	clear_line(t_line *line, int exit, t_history **history)
{
	line->result = ft_strdup(line->str->s);
	history_save(line->history_orig, line->str);
	history_clear(line->history);
	*history = line->history_orig;
	str_delete(&line->prompt);
	str_delete(&line->kill_buffer);
	str_delete(&line->hs.query);
	str_delete(&line->oldstr);
	if (exit)
	{
		ft_putstr_fd("exit", STDOUT);
		ft_strdel(&line->result);
	}
	/* clear undo stack */
}

/*
** If EOF, return NULL.
** If error, return NULL and raise g_errno.
*/

char	*ft_readline(char *prompt, char *oldline)
{
	t_line		line;
	t_vector	key_bindings;
	int			exit;

	logopen();
	sig_init();
	term_init();
	if (g_errno)
		return (NULL);
	term_setup();
	init_line(&line, prompt, oldline);
	init_bindings(line.vi_mode, &key_bindings);
	init_linebuf(&line);
	update_line(NULL);
	exit = input_loop(&line, &key_bindings);
	clear_linebuf();
	clear_line(&line, exit, &g_history);
	clear_bindings(&key_bindings);
	term_restore();
	logclose();
	return (line.result);
}