/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arr_str_qsort.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wtalea <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/19 15:57:07 by wtalea            #+#    #+#             */
/*   Updated: 2019/08/19 18:22:12 by wtalea           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_qsort.h"

static	int		cmp_pchar(const void *a, const void *b)
{
	return (ft_strcmp(*(char **)a, *(char **)b));
}

void	ft_arr_str_qsort(char **str, int len)
{
	ft_qsort(str, len, sizeof(char *), cmp_pchar);
}
