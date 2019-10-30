/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sem.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jterry <jterry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/21 17:27:04 by gmelisan          #+#    #+#             */
/*   Updated: 2019/10/30 18:06:27 by gmelisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SEM_H
# define SEM_H

# include <sys/sem.h>
# include "error.h"

# define SEMPIPE		0
# define SEMPRINT		1

void	init_sem(void);
void	clear_sem(void);
void	reserve_sem(int semnum, int n, int whl);
void	release_sem(int semnum, int n);
void	set_sem(int semnum, int val);


int		get_sem(int semnum);

#endif
