/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_attr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggwin-go <ggwin-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 18:34:07 by ggwin-go          #+#    #+#             */
/*   Updated: 2019/06/10 18:39:18 by ggwin-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

t_attr		*initialize_left(int spec, int right_fd, int left_fd, char *file)
{
	t_attr	*attr;

	attr = (t_attr*)ft_xmalloc(sizeof(t_attr));
	attr->spec.value = 0;
	attr->spec.value |= spec;
	attr->right_fd = right_fd;
	attr->left_fd = left_fd;
	attr->file = ft_strdup(file);
	attr->next = NULL;
	return (attr);
}
