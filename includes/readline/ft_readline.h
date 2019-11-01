/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_readline.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelisan <gmelisan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/03 16:35:39 by gmelisan          #+#    #+#             */
/*   Updated: 2019/11/02 01:23:02 by gmelisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_READLINE_H
# define FT_READLINE_H

# include <unistd.h>
# include <signal.h>
# include <fcntl.h>
# include <sys/ioctl.h>
# include <dirent.h>

# include "libft.h"
# include "ft_string.h"
# include "ft_vector.h"

# include "sh.h"
# include "line.h"
# include "terminal.h"
# include "keys.h"
# include "bindings.h"
# include "display.h"
# include "actions.h"
# include "history.h"
# include "history_search.h"
# include "input_loop.h"
# include "escseqs.h"
# include "loginfo.h"
# include "utils.h"
# include "undo.h"

# define DEBUG				1

# define VI_INSERT			1
# define VI_COMMAND			2

char			*gnl(char *prompt);
char			*ft_readline(char *prompt, enum e_rl_mode mode);

#endif
