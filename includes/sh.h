/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggwin-go <ggwin-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/04 17:44:12 by dwisoky           #+#    #+#             */
/*   Updated: 2019/10/12 17:43:10 by wtalea           ###   ########.fr       */
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
# include "expansion.h"

# ifdef __APPLE__
#  include <mach-o/loader.h>
# else
#  define MH_MAGIC		0x464c457f
#  define MH_MAGIC_64	0x464c457f
# endif

typedef struct		s_opt
{
	t_uint			vi_mode;
	t_uint			emacs_mode;
	t_uint			enable_color;
	t_uint			noclobber;
	t_uint			history;
	t_uint			rl_in;
	t_uint			rl_out;
	t_uint			rl_gnl;
	t_uint			is_subshell;
	t_uint			is_single_cmd;
}					t_opt;

typedef struct		s_alias
{
	struct s_alias	*next;
	char			*head;
	char			*body_alias;
}					t_alias;

void				signal_monitor();
void				shell_init(int ac, char **av);
int					check_binary(char *path);
void				shell_clear(void);
void				print_exit(void);
void				execute_line(char *buf);
int					alias_size_list(t_alias *alias);
void				fill_hash_names(void);
t_complete_cmd		*exec_ast(char *buf, t_lex **lex);

#endif
