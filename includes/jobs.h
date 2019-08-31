/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   jobs.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggwin-go <ggwin-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/11 15:57:31 by jterry            #+#    #+#             */
/*   Updated: 2019/08/31 14:19:58 by ggwin-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef JOBS_H
# define JOBS_H

# include <signal.h>
# include <setjmp.h>

typedef struct		s_jobs
{
	char			*status;
	int				num;
	char			*str_num;
	char			*name;
	int				pid;
	struct s_jobs	*next;
}					t_jobs;

extern t_jobs		*g_jobs;

void				jobs_sig();
void				deletejob(t_jobs **alst, int num);
void				jobs(t_jobs *local_job, int iter, char *cmd);
t_jobs				*ft_addjob(char *name);
t_jobs				*jobs_last_elem(t_jobs *job);
int					jobs_list_counter(t_jobs *local_job);

#endif
