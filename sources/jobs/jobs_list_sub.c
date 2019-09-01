/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   jobs_list_sub.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jterry <jterry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/01 18:37:06 by jterry            #+#    #+#             */
/*   Updated: 2019/09/01 19:48:01 by jterry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

t_job			*ft_addsubjob(char *path, int num)
{
	t_job		*new;

	new = (t_job*)malloc(sizeof(t_job));
	new->name = ft_strdup(path);
	new->status = ft_strdup("\t[Running]\t");
	new->next = NULL;
	new->num = num;
	return (new);
}
