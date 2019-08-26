/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggwin-go <ggwin-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/04 17:44:12 by dwisoky           #+#    #+#             */
/*   Updated: 2019/08/26 18:24:32 by ggwin-go         ###   ########.fr       */
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

t_lex			*lexer(char *str);
void			preliminary_check_fd(void);
void			check_quotes(char *str);
t_pars_list		*exec_ast(char *buf);
void			lllestb_string(char *buf);
void			init(void);
void			end_work(void);

typedef struct	s_options
{
	t_uint		vi_mode;
	t_uint		enable_color;
	t_uint		noclobber;
}				t_options;

#endif
