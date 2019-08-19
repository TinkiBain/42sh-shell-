/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_len_fd.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggwin-go <ggwin-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 15:16:39 by dwisoky           #+#    #+#             */
/*   Updated: 2019/08/19 23:55:57 by ggwin-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_len_fd(char const *s, size_t len, int fd)
{
	if (s == NULL)
		return ;
	while (len-- && *s != '\0')
		ft_putchar_fd(*s++, fd);
}
