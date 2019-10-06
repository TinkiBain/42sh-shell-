/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kind_of_sig.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jterry <jterry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/02 21:11:51 by jterry            #+#    #+#             */
/*   Updated: 2019/10/02 22:19:43 by jterry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

char				*core_dump_signals(int st, char *name)
{
	char *msg;

	msg = NULL;
	if (st == SIGSEGV)
		msg = ft_strjoin(" segmentation fault\t", name);
	else if (st == SIGABRT)
		msg = ft_strjoin(" abort\t", name);
	else if (st == SIGQUIT)
		msg = ft_strjoin(" quit\t", name);
	else if (st == SIGTRAP)
		msg = ft_strjoin(" trap\t", name);
	else if (st == SIGBUS)
		msg = ft_strjoin(" bus error\t", name);
	else if (st == SIGFPE)
		msg = ft_strjoin(" erroneous arithmetic operation\t", name);
	else if (st == SIGILL)
		msg = ft_strjoin(" illegal, malformed, unknown,"
									" or privileged instruction\t", name);
	else if (st == SIGSYS)
		msg = ft_strjoin(" bad argument to a system call\t", name);
	else if (st == SIGXCPU)
		msg = ft_strjoin(" duration was exceeded\t", name);
	else if (st == SIGXFSZ)
		msg = ft_strjoin(" file was exceeds the maximum allowed size\t", name);
	return (msg);
}

char			*ignored_signals(int st, char *name)
{
	char *msg;

	msg = NULL;
	if (st == SIGCONT)
		msg = ft_strjoin(" continue\t", name);
	else if (st == SIGCHLD)
		msg = ft_strjoin(" child process terminated, stopped, or continued\t", name);
	else if (st == SIGURG)
		msg = ft_strjoin(" high bandwidth data is available at a socket\t", name);
	else if (st == SIGWINCH)
		msg = ft_strjoin(" terminal window size changed\t", name);
	return (msg);
}


char			*terminal_signals(int st, char *name)
{
	char *msg;

	msg = NULL;
	if (st == SIGALRM)
		msg = ft_strjoin(" alarm\t", name);
	else if (st == SIGHUP)
		msg = ft_strjoin(" hangup\t", name);
	else if (st == SIGINT)
		msg = ft_strjoin(" terminal interrupt signal\t", name);
	else if (st == SIGKILL)
		msg = ft_strjoin(" kill\t", name);
	else if (st == SIGPIPE)
		msg = ft_strjoin(" write on a pipe with no one to read it\t", name);
	else if (st == SIGPROF)
		msg = ft_strjoin(" profiling timer expired\t", name);
	else if (st == SIGTERM)
		msg = ft_strjoin(" termination signal\t", name);
	else if (st == SIGUSR1)
		msg = ft_strjoin(" usrsignal1\t", name);
	else if (st == SIGUSR2)
		msg = ft_strjoin(" usrsignal2\t", name);
	else if (st == SIGVTALRM)
		msg = ft_strjoin(" virtual timer expired\t", name);
	return (msg);
}

char			*stop_signals(int st, char *name)
{
	char *msg;

	msg = NULL;
	if (st == SIGSTOP)
		msg = ft_strjoin(" stoped\t", name);
	else if (st == SIGTSTP)
		msg = ft_strjoin(" suspended\t", name);
	else if (st == SIGTTIN)
		msg = ft_strjoin(" background process attempting read\t", name);
	else if (st == SIGTTOU)
		msg = ft_strjoin(" background process attempting write\t", name);
	return (msg);
}

char			*that_sig(int st, char *name)
{
	char *msg;

	msg = NULL;
	if ((msg = stop_signals(st, name)))
		return (msg);
	else if ((msg = core_dump_signals(st, name)))
		return (msg);
	else if ((msg = terminal_signals(st, name)))
		return (msg);
	else if ((msg = ignored_signals(st, name)))
		return (msg);
	else
		return (msg);
}
