/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_usage.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wtalea <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/24 16:25:05 by wtalea            #+#    #+#             */
/*   Updated: 2019/08/24 16:40:01 by wtalea           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hash.h"
#include "defs.h"

void	hash_usage(void)
{
	write(STDERR, PROJECT_NAME, ft_strlen(PROJECT_NAME));
	write(STDERR, ": ", 2);
	write(STDERR, HASH_USAGE, ft_strlen(HASH_USAGE));
	write(STDERR, "\n", 1);
}

void	hash_invalid_option(char c)
{
	write(STDERR, PROJECT_NAME, ft_strlen(PROJECT_NAME));
	write(STDERR, ": ", 2);
	write(STDERR, HASH_NAME, ft_strlen(HASH_NAME));
	write(STDERR, ": -", 3);
	write(STDERR, &c, 1);
	write(STDERR, ": invalid option\n", 17);
}
