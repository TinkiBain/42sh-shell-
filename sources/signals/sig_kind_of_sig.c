/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sig_kind_of_sig.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jterry <jterry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/02 21:11:51 by jterry            #+#    #+#             */
/*   Updated: 2019/10/15 16:03:08 by jterry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

char			*core_dump_signals(int st, char *name)
{
	char *msg;

	msg = NULL;
	if (st == SIGSEGV)
		msg = ft_xstrjoin("\tsegmentation fault\t", name);
	else if (st == SIGABRT)
		msg = ft_xstrjoin("\tabort\t", name);
	else if (st == SIGQUIT)
		msg = ft_xstrjoin("\tquit\t", name);
	else if (st == SIGTRAP)
		msg = ft_xstrjoin("\ttrap\t", name);
	else if (st == SIGBUS)
		msg = ft_xstrjoin("\tbus error\t", name);
	else if (st == SIGFPE)
		msg = ft_xstrjoin("\terroneous arithmetic operation\t", name);
	else if (st == SIGILL)
		msg = ft_xstrjoin("\tillegal, malformed, unknown,"
									" or privileged instruction\t", name);
	else if (st == SIGSYS)
		msg = ft_xstrjoin("\tbad argument to a system call\t", name);
	else if (st == SIGXCPU)
		msg = ft_xstrjoin("\tduration was exceeded\t", name);
	else if (st == SIGXFSZ)
		msg = ft_xstrjoin("\tfile was exceeds the maximum size\t", name);
	return (msg);
}

char			*ignored_signals(int st, char *name)
{
	char *msg;

	msg = NULL;
	if (st == SIGCONT)
		msg = ft_xstrjoin("\tcontinue\t", name);
	else if (st == SIGCHLD)
		msg = ft_xstrjoin("\tchild process term, stop, or cont\t", name);
	else if (st == SIGURG)
		msg = ft_xstrjoin("\thigh bandwidth data is"
			"available at a socket\t", name);
	else if (st == SIGWINCH)
		msg = ft_xstrjoin("\tterminal window size changed\t", name);
	return (msg);
}

char			*terminal_signals(int st, char *name)
{
	char *msg;

	msg = NULL;
	if (st == SIGALRM)
		msg = ft_xstrjoin("\talarm\t", name);
	else if (st == SIGHUP)
		msg = ft_xstrjoin("\thangup\t", name);
	else if (st == SIGKILL)
		msg = ft_xstrjoin("\tkill\t", name);
	// else if (st == SIGPIPE)
	// 	msg = ft_xstrjoin("\twrite on a pipe with no one to read it\t", name);
	else if (st == SIGPROF)
		msg = ft_xstrjoin("\tprofiling timer expired\t", name);
	else if (st == SIGTERM)
		msg = ft_xstrjoin("\ttermination signal\t", name);
	else if (st == SIGUSR1)
		msg = ft_xstrjoin("\tusrsignal1\t", name);
	else if (st == SIGUSR2)
		msg = ft_xstrjoin("\tusrsignal2\t", name);
	else if (st == SIGVTALRM)
		msg = ft_xstrjoin("\tvirtual timer expired\t", name);
	return (msg);
}

char			*stop_signals(int st, char *name)
{
	char *msg;

	msg = NULL;
	if (st == SIGSTOP)
		msg = ft_xstrjoin("\tstoped\t", name);
	else if (st == SIGTSTP)
		msg = ft_xstrjoin("\tsuspended\t", name);
	else if (st == SIGTTIN)
		msg = ft_xstrjoin("\tbackground process attempting read\t", name);
	else if (st == SIGTTOU)
		msg = ft_xstrjoin("\tbackground process attempting write\t", name);
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
