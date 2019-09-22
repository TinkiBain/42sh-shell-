/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   traverse_compound_list.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggwin-go <ggwin-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 21:57:35 by ggwin-go          #+#    #+#             */
/*   Updated: 2019/09/22 19:54:11 by ggwin-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

void		traverse_compound_list(t_compound_list *list, t_pjobs *local)
{
	char	*str;

	str = get_job_name(list->lex_begin, list->lex_end);
	call_subshell(str, local);
}
