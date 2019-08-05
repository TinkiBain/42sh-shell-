/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_readline.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggwin-go <ggwin-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/03 16:35:39 by gmelisan          #+#    #+#             */
/*   Updated: 2019/08/05 22:08:40 by gmelisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_READLINE_H
# define FT_READLINE_H

# include <unistd.h>
# include <signal.h>
# include <fcntl.h>
# include <sys/ioctl.h>

# include "libft.h"
# include "ft_string.h"
# include "ft_vector.h"

# include "defs.h"
# include "line.h"
# include "xmalloc.h"
# include "str_xfuncs.h"
# include "vec_xfuncs.h"
# include "ft_errno.h"
# include "terminal.h"
# include "keys.h"
# include "bindings.h"
# include "display.h"
# include "signal_handlers.h"
# include "actions.h"
# include "history.h"
# include "history_search.h"
# include "input_loop.h"
# include "escseqs.h"
# include "loginfo.h"

# define DEBUG				1

# define VI_INSERT			1
# define VI_COMMAND			2

t_history		*g_history;

struct 			s_options
{
	int vi_mode;
}				g_options;

// typedef struct	s_rlargs
// {
// 	char		*prompt;
// 	t_history	**history;
// 	int			vi_mode;
// }				t_rlargs;

char			*ft_readline(char *prompt, char *oldline);

#endif
