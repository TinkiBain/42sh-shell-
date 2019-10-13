/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sem.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelisan <gmelisan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/21 17:27:04 by gmelisan          #+#    #+#             */
/*   Updated: 2019/10/13 14:25:41 by gmelisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SEM_H
# define SEM_H

# include <sys/sem.h>
# include "error.h"

# ifdef __linux__

union	semun {
	int				val;
	struct semid_ds	*buf;
	unsigned short	*array;
};

# endif

void	init_sem(void);
void	clear_sem(void);
void	reserve_sem(void);
void	release_sem(void);

#endif
