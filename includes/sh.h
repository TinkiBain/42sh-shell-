/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggwin-go <ggwin-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/04 17:44:12 by dwisoky           #+#    #+#             */
/*   Updated: 2019/09/01 15:53:24 by gmelisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SH_H
# define SH_H

# include <sys/wait.h>
# include <pwd.h>
# include "defs.h"
# include "libft.h"
# include "ast.h"
# include "hash.h"
# include "ft_readline.h"
# include "variables.h"
# include "lib_wtalea.h"
# include "xfuncs.h"
# include "jobs.h"

typedef struct	s_opt
{
	t_uint		vi_mode;
	t_uint		emacs_mode;
	t_uint		enable_color;
	t_uint		noclobber;
	t_uint		rl_in;
	t_uint		rl_out;
}				t_opt;

int				check_file_errors(const char *file_name, int flag);
int				return_error(const char *file_name, const char *error);
t_pars_list		*exec_ast(char *buf);
void			main_gnl_loop(int fd, char *filename);
void			main_readline_loop(void);
void			shell_init(char *project_name);
void			shell_init_readline(void);
void			shell_clear(void);

int				g_check_nl;

#endif
