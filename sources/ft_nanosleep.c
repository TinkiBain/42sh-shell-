/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nanosleep.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jterry <jterry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/02 16:59:00 by jterry            #+#    #+#             */
/*   Updated: 2019/11/02 16:59:20 by jterry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <time.h>

void				ft_nanosleep(long sec, long nsec)
{
	struct timespec tw;
	struct timespec tr;

	tw.tv_sec = sec;
	tw.tv_nsec = nsec;
	nanosleep(&tw, &tr);
}
