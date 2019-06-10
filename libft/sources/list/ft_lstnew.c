/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggwin-go <ggwin-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/02 12:39:14 by ggwin-go          #+#    #+#             */
/*   Updated: 2019/04/23 22:59:11 by ggwin-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(const char *name, const char *path)
{
	t_list	*lst;

	if (!name || !path || !(lst = (t_list *)malloc(sizeof(t_list))))
		return (NULL);
	lst->next = NULL;
	if (!(lst->name = ft_strdup_len(name, &(lst->name_len))))
	{
		free(lst);
		return (NULL);
	}
	if (!(lst->path = ft_strdup_len(path, &(lst->path_len))))
	{
		free(lst->name);
		free(lst);
		return (NULL);
	}
	return (lst);
}
