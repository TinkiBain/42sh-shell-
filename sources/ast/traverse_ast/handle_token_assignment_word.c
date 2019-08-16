/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_token_assignment_word.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggwin-go <ggwin-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/05 21:42:57 by ggwin-go          #+#    #+#             */
/*   Updated: 2019/08/16 21:46:07 by ggwin-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

void	handle_token_assignment_word(char *word, char ***env)
{
	set_var((const char *)word, env, 0);
}
