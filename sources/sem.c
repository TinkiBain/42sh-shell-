/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sem.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jterry <jterry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/21 17:25:33 by gmelisan          #+#    #+#             */
/*   Updated: 2019/10/13 19:15:02 by jterry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sem.h"

int					g_semid;

void				init_sem(void)
{
	union semun		arg;

	g_semid = semget(IPC_PRIVATE, 1, S_IRUSR | S_IWUSR | IPC_CREAT | IPC_EXCL);
	arg.val = 0;
	if (semctl(g_semid, 0, SETVAL, arg) == -1)
		print_error("init_sem()", "Error in semctl()");
}

void				clear_sem(void)
{
	if (semctl(g_semid, 0, IPC_RMID) == -1)
		print_error("clear_sem()", "Error in semctl()");
	g_semid = 0;
}

void				reserve_sem(int n)
{
	struct sembuf	sops;

	if (!g_semid)
		return ;
	sops.sem_num = 0;
	sops.sem_op = -n;
	sops.sem_flg = 0;
	if (semop(g_semid, &sops, 1) == -1)
		;
}

void				release_sem(int n)
{
	struct sembuf	sops;

	if (!g_semid)
		return ;
	sops.sem_num = 0;
	sops.sem_op = n;
	sops.sem_flg = 0;
	semop(g_semid, &sops, 1);
}

int					get_sem(void)
{
	extern int		g_semid;
	union semun		arg;

	ft_bzero(&arg, sizeof(arg));
	if (g_semid)
		return (semctl(g_semid, 0, GETVAL, arg));
	return (99);
}
