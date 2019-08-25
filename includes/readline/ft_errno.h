/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_errno.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggwin-go <ggwin-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/24 20:33:48 by ggwin-go          #+#    #+#             */
/*   Updated: 2019/08/24 20:33:49 by ggwin-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ERRNO_H
# define FT_ERRNO_H

# include "ft_readline.h"

enum	e_errno
{
	E_READ = 1042,
};

extern int	g_errno;

# define ERRINFOLEN		64

char	g_errinfo[ERRINFOLEN];

void	printerr(void);
void	fatal(char *msg);

#endif
