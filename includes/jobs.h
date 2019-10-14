/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   jobs.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jterry <jterry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/11 15:57:31 by jterry            #+#    #+#             */
/*   Updated: 2019/10/14 18:10:09 by jterry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef JOBS_H
# define JOBS_H

# include <signal.h>
# include <setjmp.h>

# define SUSPINT 5503
# define SUSPOUT 5759
# define SUSPCHLD 4735
# define SUSTOP 4479

typedef struct		s_job
{
	char			*status;
	int				num;
	char			*name;
	int				pid;
	struct s_job	*next;
}					t_job;

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

extern t_pjobs		*g_pjobs;
extern t_pjobs		*g_subjob;
extern int			g_wait_flags;
extern int			*g_pipe_pid;

t_pjobs				*ljobs_startet(char *str, int flag, int num, int pid);
t_job				*pid_checl(int pid, t_job *job);
t_job				*job_finder(int pid, t_pjobs *local);
t_pjobs				*jobs_find_num(t_pjobs *local, int num);
t_pjobs				*name_proc_hendl(t_pjobs *local_job, char *name);
t_pjobs				*subjob_changer(char *str, t_pjobs **gjobs, int flag);
t_pjobs				*jobs_startet(char *str, int sep);
t_pjobs				*ft_addjob(char *name, int flag);
t_pjobs				*jobs_last_elem(t_pjobs *job);
void				jobs_sig();
void				freedsubjob(t_job **new);
void				deletejob(t_pjobs **alst, int num);
int					jobs(t_pjobs *local_job, int iter, const char *cmd);
int					jobs_list_counter(t_pjobs *local_job);
int					find_highnum(t_pjobs *local);
int					ft_waitpid(pid_t pid);
int					pipe_av(t_job *job, int counter);

char				*core_dump_signals(int st, char *name);
char				*ignored_signals(int st, char *name);
char				*terminal_signals(int st, char *name);
char				*stop_signals(int st, char *name);
char				*that_sig(int st, char *name);
void				sig_per_stop(int done_pid, t_job *job, char *msg,
								t_pjobs *first);
void				pjobs_sig(int sig, int done_pid);

#endif
