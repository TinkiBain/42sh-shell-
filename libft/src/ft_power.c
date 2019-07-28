/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_power.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelisan <gmelisan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 14:15:39 by gmelisan          #+#    #+#             */
/*   Updated: 2018/12/04 17:27:10 by gmelisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_power(int n, int power)
{
	int i;
	int result;

	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	i = 0;
	result = 1;
	while (i < power)
	{
		result *= n;
		i++;
	}
	return (result);
}
