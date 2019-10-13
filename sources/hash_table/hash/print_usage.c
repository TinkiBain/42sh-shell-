/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_usage.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wtalea <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/24 16:25:05 by wtalea            #+#    #+#             */
/*   Updated: 2019/10/13 12:22:32 by wtalea           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hash.h"
#include "defs.h"
#include "error.h"

void	hash_usage(void)
{
	ft_putstr(HASH_NAME);
	ft_putstr(": ");
	ft_putendl_fd(HASH_USAGE, STDERR);
}

void	hash_invalid_option(char c)
{
	print_error_vaarg(HASH_NAME ": -%c: invalid option\n", c);
}

void	hash_empty(void)
{
	print_error(HASH_NAME, "hash table empty");
}

void	hash_not_found(char *name)
{
	print_error_vaarg(HASH_NAME ": %s: not found\n", name);
}
