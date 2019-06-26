/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atolli.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwisoky <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/11 04:09:52 by dwisoky           #+#    #+#             */
/*   Updated: 2019/05/11 04:15:20 by dwisoky          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned long long int	ft_atolli(char *str)
{
	int						i;
	unsigned long long int	tmp;

	i = 0;
	tmp = 0;
	while (str[i] && i < 18)
	{
		tmp = tmp * 10 + (str[i] - '0');
		++i;
	}
	return (tmp);
}
