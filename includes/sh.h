/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggwin-go <ggwin-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/04 17:44:12 by dwisoky           #+#    #+#             */
/*   Updated: 2019/09/14 19:02:55 by gmelisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SH_H
# define SH_H

# include <sys/wait.h>
# include <pwd.h>
# include "defs.h"
# include "libft.h"
# include "error.h"
# include "ast.h"
# include "hash.h"
# include "ft_readline.h"
# include "variables.h"
# include "lib_wtalea.h"
# include "xfuncs.h"
# include "jobs.h"
# include "builtins.h"

typedef struct	s_opt
{
	t_uint		vi_mode;
	t_uint		emacs_mode;
	t_uint		enable_color;
	t_uint		noclobber;
	t_uint		rl_in;
	t_uint		rl_out;
}				t_opt;

typedef struct	s_alias
{
	struct s_alias	*next;
	char			*head;
	char			*body_alias;
}				t_alias;

void			signal_monitor();
int				check_file_errors(const char *file_name, int flag);
int				return_error(const char *file_name, const char *error);
t_complete_cmd	*exec_ast(char *buf, t_lex **lex);
void			main_gnl_loop(int fd, char *filename);
void			main_readline_loop(void);
void			shell_init(int ac, char **av);
void			shell_init_readline(void);
void			shell_clear(void);

#endif
