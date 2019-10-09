/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sem.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggwin-go <ggwin-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/21 17:25:33 by gmelisan          #+#    #+#             */
/*   Updated: 2019/10/09 14:28:56 by gmelisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sem.h"

int					g_semid;

void				init_sem(void)
{
	union semun		arg;

	g_semid = semget(IPC_PRIVATE, 1, S_IRUSR | S_IWUSR | IPC_CREAT | IPC_EXCL);
	arg.val = 1;
	if (semctl(g_semid, 0, SETVAL, arg) == -1)
		print_error("init_sem()", "Error in semctl()");
}

void				clear_sem(void)
{
	if (semctl(g_semid, 0, IPC_RMID) == -1)
		print_error("clear_sem()", "Error in semctl()");
	g_semid = 0;
}

void				reserve_sem(void)
{
	struct sembuf	sops;

	if (!g_semid)
		return ;
	sops.sem_num = 0;
	sops.sem_op = -1;
	sops.sem_flg = 0;
	while (semop(g_semid, &sops, 1) == -1)
		;
}

void				release_sem(void)
{
	struct sembuf	sops;

	if (!g_semid)
		return ;
	sops.sem_num = 0;
	sops.sem_op = 1;
	sops.sem_flg = 0;
	semop(g_semid, &sops, 1);
}
