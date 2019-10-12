/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sig_kind_of_sig.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jterry <jterry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/02 21:11:51 by jterry            #+#    #+#             */
/*   Updated: 2019/10/12 17:34:37 by jterry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

char			*core_dump_signals(int st, char *name)
{
	char *msg;

	msg = NULL;
	if (st == SIGSEGV)
		msg = ft_xstrjoin(" segmentation fault\t", name);
	else if (st == SIGABRT)
		msg = ft_xstrjoin(" abort\t", name);
	else if (st == SIGQUIT)
		msg = ft_xstrjoin(" quit\t", name);
	else if (st == SIGTRAP)
		msg = ft_xstrjoin(" trap\t", name);
	else if (st == SIGBUS)
		msg = ft_xstrjoin(" bus error\t", name);
	else if (st == SIGFPE)
		msg = ft_xstrjoin(" erroneous arithmetic operation\t", name);
	else if (st == SIGILL)
		msg = ft_xstrjoin(" illegal, malformed, unknown,"
									" or privileged instruction\t", name);
	else if (st == SIGSYS)
		msg = ft_xstrjoin(" bad argument to a system call\t", name);
	else if (st == SIGXCPU)
		msg = ft_xstrjoin(" duration was exceeded\t", name);
	else if (st == SIGXFSZ)
		msg = ft_xstrjoin(" file was exceeds the maximum allowed size\t", name);
	return (msg);
}

char			*ignored_signals(int st, char *name)
{
	char *msg;

	msg = NULL;
	if (st == SIGCONT)
		msg = ft_xstrjoin(" continue\t", name);
	else if (st == SIGCHLD)
		msg = ft_xstrjoin(" child process term, stop, or cont\t", name);
	else if (st == SIGURG)
		msg = ft_xstrjoin(" high bandwidth data is"
			"available at a socket\t", name);
	else if (st == SIGWINCH)
		msg = ft_xstrjoin(" terminal window size changed\t", name);
	return (msg);
}

char			*terminal_signals(int st, char *name)
{
	char *msg;

	msg = NULL;
	if (st == SIGALRM)
		msg = ft_xstrjoin(" alarm\t", name);
	else if (st == SIGHUP)
		msg = ft_xstrjoin(" hangup\t", name);
	else if (st == SIGINT)
		msg = ft_xstrjoin(" terminal interrupt signal\t", name);
	else if (st == SIGKILL)
		msg = ft_xstrjoin(" kill\t", name);
	else if (st == SIGPIPE)
		msg = ft_xstrjoin(" write on a pipe with no one to read it\t", name);
	else if (st == SIGPROF)
		msg = ft_xstrjoin(" profiling timer expired\t", name);
	else if (st == SIGTERM)
		msg = ft_xstrjoin(" termination signal\t", name);
	else if (st == SIGUSR1)
		msg = ft_xstrjoin(" usrsignal1\t", name);
	else if (st == SIGUSR2)
		msg = ft_xstrjoin(" usrsignal2\t", name);
	else if (st == SIGVTALRM)
		msg = ft_xstrjoin(" virtual timer expired\t", name);
	return (msg);
}

char			*stop_signals(int st, char *name)
{
	char *msg;

	msg = NULL;
	if (st == SIGSTOP)
		msg = ft_xstrjoin(" stoped\t", name);
	else if (st == SIGTSTP)
		msg = ft_xstrjoin(" suspended\t", name);
	else if (st == SIGTTIN)
		msg = ft_xstrjoin(" background process attempting read\t", name);
	else if (st == SIGTTOU)
		msg = ft_xstrjoin(" background process attempting write\t", name);
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
