/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_readline.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggwin-go <ggwin-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/03 16:29:42 by gmelisan          #+#    #+#             */
/*   Updated: 2019/09/03 22:48:02 by gmelisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_readline.h"

t_line			*g_line;
extern t_opt	g_opt;

static void	sig_init(void)
{
	signal(SIGINT, sigh_ignore);
	signal(SIGTSTP, SIG_DFL);
	signal(SIGSEGV, sigh_sigsegv);
	signal(SIGABRT, sigh_sigabrt);
	signal(SIGWINCH, sigh_sigwinch);
	signal(SIGTERM, sigh_sigterm);
}

static void	init_line(t_line *line, char *prompt, char *oldline)
{
	t_string		temp_str;
	extern t_opt	g_opt;

	ft_bzero(line, sizeof(t_line));
	line->history_orig = g_history;
	line->history = history_copy(g_history);
	temp_str = str_xcreate(0);
	history_push(line->history, temp_str);
	line->str = (t_string *)line->history->item->content;
	line->prompt = str_xcopy(prompt ? prompt : "");
	convert_escapes(&line->prompt);
	line->vi_mode = g_opt.vi_mode;
	line->emacs_mode = g_opt.emacs_mode;
	line->oldstr = str_xcopy(oldline);
	line->arg = 1;
	init_bindings(line->vi_mode, &line->key_bindings);
	push_undo_list(line);
}

static void	clear_line(t_line *line, int exit, t_history **history)
{
	line->result = str_xduplicate(*line->str);
	str_xaddfront(&line->result, line->oldstr.s, line->oldstr.len);
	history_save(line->history_orig, line->str);
	history_clear(line->history);
	*history = line->history_orig;
	str_delete(&line->prompt);
	str_delete(&line->kill_buffer);
	str_delete(&line->hs.query);
	str_delete(&line->oldstr);
	str_delete(&line->keybuf);
	clear_bindings(&line->key_bindings);
	if (exit)
		str_delete(&line->result);
	ft_lstdel(&(line->undo), del_undo_one);
}

/*
** If EOF, return NULL.
** If error, write message and return NULL.
** Possible errors: E_READ
*/

char		*ft_readline(char *prompt, char *oldline)
{
	t_line			line;
	int				exit;

	sig_init();
	g_line = &line;
	if (!g_opt.emacs_mode && !g_opt.vi_mode)
		return (gnl(prompt, oldline));
	term_init();
	term_setup();
	init_line(&line, prompt, oldline);
	init_linebuf(&line);
	update_line(NULL);
	exit = input_loop(&line);
	clear_linebuf();
	clear_line(&line, exit, &g_history);
	term_restore();
	return (line.result.s);
}
