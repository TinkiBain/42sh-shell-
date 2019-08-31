/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jterry <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/11 15:57:31 by jterry            #+#    #+#             */
/*   Updated: 2019/08/26 15:19:46 by jterry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <signal.h>
# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <unistd.h>
# include <sys/wait.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <dirent.h>
# include <pwd.h>
# include <limits.h>
# include "libft/libft.h"
# include <sys/stat.h>
# include <setjmp.h>

typedef struct		s_cmd
{
	char			*name;
	char			*path;
	struct s_cmd	*next;
}					t_cmd;

typedef struct		s_jobs
{
	char			*status;
	int				num;
	char			*str_num;
	char			*name;
	int				PID;
	struct s_jobs	*next;
}					t_jobs;

t_jobs				*joba;
char				*g_str;
char				**g_commands;
jmp_buf				g_envs;

/*
** jobs
*/

void				jobs_sig();
void				deletejob(t_jobs **alst, int num);
void				ft_kill(char **cmd, t_jobs *local_job, int sig);
void				fg(t_jobs *local_job, char *name);
void				jobs(t_jobs *local_job, int iter, char *cmd);
t_jobs				*ft_addjob(char *name);
void				bg(t_jobs *local_job, char *name);

/*
** other
*/

void				sokr(char ***tmp_env, char **command);
int					command_check(char ***tmp_env, char **command, t_cmd **cmds);
void				print_err(char *str, int bits, char *cmd);
void				cd_command(char **command, char ***tmp_env);
void				key_free(char **tmp);
char				**commands_completion(const char *text, int start, int end);
t_cmd				*ft_preload_cmd(char **tmp_env);
char				**ft_envcreat(char **env);
int					tilda_check(char ***command, char **tmp_env);
char				**ft_dollar(char *com, char **tmp_env);
void				unsetenv_command(char ***tmp_env, char **command, t_cmd **cmds);
void				setenv_command(char ***tmp_env, char **command, t_cmd **cmds);
char				**ft_setenv(char **tmp_env, char *str, char *str2);
int					all_command(char **command, char **tmp_env, t_cmd *cmds);
void				echo_command(char **command, int i, int j, int flag);
int					ft_getenv(char **tmp_env, char *str, char **buf);
void				env_command(char **tmp_env);

#endif
