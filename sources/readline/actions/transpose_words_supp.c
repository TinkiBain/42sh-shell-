/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transpose_words_supp.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wtalea <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 18:14:58 by wtalea            #+#    #+#             */
/*   Updated: 2019/08/06 18:37:01 by wtalea           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "actions.h"

void		tw_trans_words(char *str, char *add, int len, t_line *line)
{
	int		lens[3];
	char	*sp;
	char	*temp;

	temp = NULL;
	ft_bzero(lens, (sizeof(int) * 3));
	while (ft_isalnum(*(str + lens[0])))
		++lens[0];
	while (ft_isspace(*(str + lens[0] + lens[1])))
		++lens[1];
	if ((sp = ft_strnew(lens[1])) == NULL)
		die();
	ft_memcpy(sp, (str + lens[0]), lens[1]);
	while (*(str + lens[0] + lens[1] + lens[2]) && (lens[0] + lens[1] + lens[2])
			<= len && ft_isalnum(*(str + lens[0] + lens[1] + lens[2])))
		++(lens[2]);
	if ((temp = ft_strnew(lens[0])) == NULL)
		die();
	ft_memcpy(temp, str, lens[0]);
	ft_memcpy(str, (str + lens[0] + lens[1]), lens[2]);
	ft_memcpy(str + lens[2], sp, lens[1]);
	ft_memcpy((str + lens[2] + lens[1]), temp, lens[0]);
	line->cpos = str - add + len + ft_isalnum(*(str + len));
	free(sp);
	free(temp);
}
