/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sem.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jterry <jterry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/21 17:25:33 by gmelisan          #+#    #+#             */
/*   Updated: 2019/10/13 19:44:15 by gmelisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sem.h"

int					g_semid;

void				init_sem(void)
{
	g_semid = semget(IPC_PRIVATE, 2, S_IRUSR | S_IWUSR | IPC_CREAT | IPC_EXCL);
	if (g_semid == -1)
	{
		loginfo("Error in init_sem()");
		g_semid = 0;
	}
	set_sem(SEMPIPE, 0);
	set_sem(SEMPRINT, 1);
}

void				clear_sem(void)
{
	if (semctl(g_semid, SEMPIPE, IPC_RMID) == -1)
		loginfo("Error in clear_sem() SEMPIPE");
	if (semctl(g_semid, SEMPRINT, IPC_RMID) == -1)
		loginfo("Error in clear_sem() SEMPRINT");
	g_semid = 0;
}

void				reserve_sem(int semnum, int n)
{
	struct sembuf	sops;

	if (!g_semid)
		return ;
	sops.sem_num = semnum;
	sops.sem_op = -n;
	sops.sem_flg = 0;
	if (semop(g_semid, &sops, 1) == -1)
		;
}

void				release_sem(int semnum, int n)
{
	struct sembuf	sops;

	if (!g_semid)
		return ;
	sops.sem_num = semnum;
	sops.sem_op = n;
	sops.sem_flg = 0;
	semop(g_semid, &sops, 1);
}

void				set_sem(int semnum, int val)
{
	union semun		arg;

	arg.val = val;
	if (semctl(g_semid, semnum, SETVAL, arg) == -1)
		loginfo("Error while set_sem(%d, %d)", semnum, val);
}

/* int					get_sem(void) */
/* { */
/* 	extern int		g_semid; */
/* 	union semun		arg; */

/* 	ft_bzero(&arg, sizeof(arg)); */
/* 	if (g_semid) */
/* 		return (semctl(g_semid, 0, GETVAL, arg)); */
/* 	return (0); */
/* } */
