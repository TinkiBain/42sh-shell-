/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggwin-go <ggwin-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/11 16:25:32 by ggwin-go          #+#    #+#             */
/*   Updated: 2019/06/11 18:09:03 by ggwin-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vector.h"
#include "libft.h"
#include <stdio.h>

void	print_vector(t_vector *vector)
{
	size_t		i;

	i = 0;
	printf("count = %zu\ncapacity = %zu\nData:\n", vector->count, vector->capacity);
	while (i < vector->count)
	{
		printf("%s\n", (char *)(vector->data)[i]);
		++i;
	}
}

int		main(int ac, char **av)
{
	t_vector	*vector;

	vector = ft_vector_init(ft_strdup("Test"));
	while (ac--)
	{
		++av;
		printf("\n");
		print_vector(vector);
		ft_vector_add(vector, (void *)*av);
	}
	return (1);
}
