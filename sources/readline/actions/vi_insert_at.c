/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vi_insert_at.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelisan <gmelisan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/05 21:01:06 by gmelisan          #+#    #+#             */
/*   Updated: 2019/08/05 21:01:09 by gmelisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "actions.h"

void	vi_insert_at(t_line *line)
{
	line->vi_mode = VI_INSERT;
}
