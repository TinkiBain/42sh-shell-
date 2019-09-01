/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   jobs.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jterry <jterry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/11 15:57:31 by jterry            #+#    #+#             */
/*   Updated: 2019/09/01 19:24:36 by jterry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef JOBS_H
# define JOBS_H

# include <signal.h>
# include <setjmp.h>

typedef struct		s_pjobs
{
	char			*name;
	int				flag;
	int				num;
	int				workgpid;
	char			*status;
	struct s_pjobs	*next;
	struct s_job	*job;
}					t_pjobs;

typedef struct		s_job
{
	char			*status;
	int				num;
	char			*name;
	int				pid;
	struct s_job	*next;
}					t_job;

extern t_pjobs		*g_pjobs;
extern t_pjobs		*g_subjob;

t_job				*job_finder(int pid, t_pjobs *local);
t_pjobs				*name_proc_hendl(t_pjobs *local_job, char *name);
t_pjobs				*subjob_changer(char *str, t_pjobs **gjobs, int flag);
t_pjobs				*jobs_startet(char *str, char **argv);
void				jobs_sig();
void				deletejob(t_pjobs **alst, int num);
void				jobs(t_pjobs *local_job, int iter, char *cmd);
t_pjobs				*ft_addjob(char *name, int flag);
t_pjobs				*jobs_last_elem(t_pjobs *job);
int					jobs_list_counter(t_pjobs *local_job);

#endif
