/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defs.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelisan <gmelisan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/04 10:15:13 by gmelisan          #+#    #+#             */
/*   Updated: 2019/11/02 01:23:55 by gmelisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFS_H
# define DEFS_H

# define PROJECT_NAME			"42sh"
# define VERSION				"0.1"

# define DEFAULT_PROMPT			"%red%w >%eoc "

# define TMP_PATH				"/tmp/" PROJECT_NAME "_tmp"
# define DEFAULT_TEXTEDITOR		"/usr/bin/vim"
# define EDPATH					"/bin/ed"

# define STDIN					0
# define STDOUT					1
# define STDERR					2

# define DEFAULT_HISTSIZE		"20"

# ifdef __linux__
#  define LINUX					1
# else
#  define LINUX					0
# endif

extern char						*g_project_name;
extern int						g_res_exec;
extern int						*g_open_fd;
extern int						g_is_interrupt;
extern char						*g_shell_path;
extern char						**g_prefix_vars;

enum	e_rl_mode
{
	RL_DEFAULT,
	RL_APPEND,
	RL_HEREDOC
};

#endif
