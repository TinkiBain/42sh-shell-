/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sem.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelisan <gmelisan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/21 17:27:04 by gmelisan          #+#    #+#             */
/*   Updated: 2019/10/14 15:46:58 by gmelisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SEM_H
# define SEM_H

# include <sys/sem.h>
# include "error.h"

# define SEMPIPE		0
# define SEMPRINT		1

# ifdef __linux__
union semun {
	int				val;
	struct semid_ds	*buf;
	unsigned short	*array;
};
# endif

void	init_sem(void);
void	clear_sem(void);
void	reserve_sem(int semnum, int n);
void	release_sem(int semnum, int n);
void	set_sem(int semnum, int val);

/*
** int		get_sem(void);
*/

#endif
