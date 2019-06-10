/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggwin-go <ggwin-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 18:12:51 by ggwin-go          #+#    #+#             */
/*   Updated: 2019/01/07 14:47:57 by ggwin-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(const char *str)
{
	long			res;
	long			tmp;
	unsigned char	neg;
	char			ch;

	while ((ch = *str) == '\n' || ch == '\t' || ch == '\r'
			|| ch == '\f' || ch == ' ' || ch == '\v')
		str++;
	neg = (ch == '-') ? 1 : 0;
	res = 0;
	if (ch == '-' || ch == '+')
		str++;
	while ((ch = *str) >= '0' && ch <= '9')
	{
		if ((((tmp = res * 10) / 10) != res)
				|| (res = tmp + (ch - '0')) < 0)
			return ((neg) ? 0 : (-1));
		str++;
	}
	if (neg)
		return (-res);
	else
		return (res);
}
