/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_readline.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jterry <jterry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/03 16:29:42 by gmelisan          #+#    #+#             */
/*   Updated: 2019/09/15 18:05:59 by gmelisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_readline.h"

t_line			*g_line;
extern t_opt	g_opt;

static void	sig_init(void)
{
	signal(SIGINT, sigh_ignore);
	signal(SIGSEGV, sigh_sigsegv);
	signal(SIGABRT, sigh_sigabrt);
	signal(SIGWINCH, sigh_sigwinch);
	signal(SIGTERM, sigh_sigterm);
}

static void	init_line(t_line *line, char *prompt, enum e_rl_mode mode)
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
	line->arg = 1;
	line->mode = mode;
	init_bindings(line->vi_mode, &line->key_bindings);
	push_undo_list(line);
}

static void	clear_line(t_line *line, int clear_flag, t_history **history)
{
	line->result = str_xduplicate(*line->str);
	if (line->mode == RL_HEREDOC)
		str_delete(line->str);
	history_save(line->history_orig, line->str);
	history_clear(line->history);
	*history = line->history_orig;
	str_delete(&line->prompt);
	str_delete(&line->kill_buffer);
	str_delete(&line->hs.query);
	str_delete(&line->keybuf);
	clear_bindings(&line->key_bindings);
	if (clear_flag)
		str_delete(&line->result);
	ft_lstdel(&(line->undo), del_undo_one);
}

/*
** If EOF, return NULL and set g_eof to 1.
** If error, write message and return NULL.
*/

char		*ft_readline(char *prompt, enum e_rl_mode mode)
{
	extern int		g_eof;
	extern int		g_line_num;
	t_line			line;
	int				ret;

	g_eof = 0;
	g_line_num++;
	sig_init();
	g_line = &line;
	if (!g_opt.emacs_mode && !g_opt.vi_mode)
		return (gnl(prompt));
	term_init();
	term_setup();
	init_line(&line, prompt, mode);
	init_linebuf(&line);
	update_line(NULL, 1);
	ret = input_loop(&line);
	clear_linebuf();
	clear_line(&line, ret, &g_history);
	term_restore();
	loginfo("Readline returned \"%s\"", line.result.s);
	return (line.result.s);
}
