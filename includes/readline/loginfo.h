/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loginfo.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggwin-go <ggwin-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/02 23:04:13 by gmelisan          #+#    #+#             */
/*   Updated: 2019/08/09 14:54:32 by gmelisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LOGINFO_H
# define LOGINFO_H

# include <stdarg.h>
# include <execinfo.h>
# include "ft_readline.h"

# define DEFAULT_LOG_PATH	"./42sh.log"
# define LOG_PATH			"~/.42sh.log"
# define BT_BUFSIZE			32

void	logopen(void);
void	logclose(void);
void	loginfo(char *format, ...);
void	loginfo_line(t_line *line);
void	loginfo_backtrace(void);

int	g_logfd;

#endif
