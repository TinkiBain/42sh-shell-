/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   traverse_compound_list.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jterry <jterry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 21:57:35 by ggwin-go          #+#    #+#             */
/*   Updated: 2019/10/24 20:30:12 by jterry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

void		traverse_compound_list(t_compound_list *list, t_pjobs **local)
{
	char	*str;

	str = get_job_name(list->lex_begin, list->lex_end);
	call_subshell(str, local);
}
