/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_token_assignment_word.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggwin-go <ggwin-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/05 21:42:57 by ggwin-go          #+#    #+#             */
/*   Updated: 2019/08/05 21:43:07 by ggwin-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

void	handle_token_assignment_word(char *word)
{
	char	*p;
	char	*name;
	char	*value;

	p = ft_strchr(word, '=');
	if (p)
	{
		name = ft_strndup(word, p - word);
		value = ft_strdup(p + 1);
	}
}
