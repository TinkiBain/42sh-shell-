/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_vi_motion.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelisan </var/spool/mail/vladimir>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/15 05:29:03 by gmelisan          #+#    #+#             */
/*   Updated: 2019/08/15 05:59:43 by gmelisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "actions.h"

int		is_vi_motion(t_action action)
{
	if (action == beginning_of_line				   /* 0 */
		|| action == backward_word				   /* b */
		|| action == forward_char				   /* l */
		|| action == vi_beginning_of_line_nonblank /* ^ */
		|| action == end_of_line				   /* $ */
		|| action == forward_word				   /* e */
		|| action == backward_char				   /* h */
								/* add: F W ; E f T w | , B t */
		)
		return (1);
	return (0);
}
