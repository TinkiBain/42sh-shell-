/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_nm.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wtalea <wtalea@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 17:24:43 by wtalea            #+#    #+#             */
/*   Updated: 2019/08/26 20:34:59 by wtalea           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "hash.h"

static	void	ft_ftitoa(int len, int i, int n, char *nb)
{
	while (len-- > i)
	{
		*(nb + len) = ft_abs((n % 10)) + '0';
		n /= 10;
	}
}

static	void	fill_null(char *nb)
{
	*nb = '0';
	*(nb + 1) = '\0';
}

void			ft_itoa_nm(int n, char *nb)
{
	int		i;
	int		len;
	int		ncp;

	if (n == 0)
		fill_null(nb);
	else
	{
		i = 0;
		len = 0;
		ncp = n;
		while (ncp != 0)
		{
			++len;
			ncp /= 10;
		}
		n < 0 ? len++ : (1);
		nb[len] = '\0';
		if (n < 0)
		{
			*(nb + i++) = '-';
			len--;
		}
		ft_ftitoa(len, i, n, nb);
	}
}
